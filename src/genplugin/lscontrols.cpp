#include "lscontrols.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSCONTROLS, "LsControls", QtDebugMsg )


/**************************************************************************************************/
LsControls::LsControls( const QString &a_name, QObject *a_parent )
    : QObject( a_parent )
    , m_name( a_name )
{
    qCDebug( LOG_LSCONTROLS ) << "LsControls()";
}

/**************************************************************************************************/
LsControls::~LsControls()
{
    qCDebug( LOG_LSCONTROLS ) << "~LsControls()";
}

/**************************************************************************************************/
void LsControls::render()
{
    qCDebug( LOG_LSCONTROLS ) << "render()";

    initImages();
    initOutline();
    renderOutline();
    renderEdgeHighlight();
    renderEdgeShadow();
    renderOcclusion();
    flattenImage();
    saveResult();
}

/**************************************************************************************************/
void LsControls::renderOutline()
{
    qCDebug( LOG_LSCONTROLS ) << "renderOutline()";

    // Prepare empty transparent image
    QPainter painter( &m_imgOutline );
    painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

    // Darken hole
    painter.setPen( Qt::NoPen );
    painter.fillPath( m_contour, QBrush( QColor( 0, 0, 0, 32 ) ) );
}

/**************************************************************************************************/
void LsControls::renderEdgeHighlight()
{
    qCDebug( LOG_LSCONTROLS ) << "renderEdgeHighlight()";
    {
        m_imgEdgehighlight.fill( 0xffffffff );

        QPainter painter( &m_imgEdgehighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_contour, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgEdgehighlight = calcVertDerivative( m_imgEdgehighlight, false, QColor( 255, 255, 255, 64) );
    m_imgEdgehighlight = blurImage( m_imgEdgehighlight, 4 );
}

/**************************************************************************************************/
void LsControls::renderEdgeShadow()
{
    qCDebug( LOG_LSCONTROLS ) << "renderEdgeShadow()";
    {
        m_imgEdgeshadow.fill( 0xffffffff );

        QPainter painter( &m_imgEdgeshadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_contour, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgEdgeshadow = calcVertDerivative( m_imgEdgeshadow, true, QColor( 0, 0, 0, 192) );
    m_imgEdgeshadow = blurImage( m_imgEdgeshadow, 8 );
}

/**************************************************************************************************/
void LsControls::renderOcclusion()
{
    qCDebug( LOG_LSCONTROLS ) << "renderOcclusion()";
    {
        m_imgOcclusion.fill( 0xffffffff );

        QPainter painter( &m_imgOcclusion );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_contour, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOcclusion = calcOmniDerivative( m_imgOcclusion, QColor( 0, 0, 0, 192) );
    m_imgOcclusion = blurImage( m_imgOcclusion, 8 );
}

/**************************************************************************************************/
void LsControls::flattenImage()
{
    qCDebug( LOG_LSCONTROLS ) << "flattenImage()";

    // Merge edge shadow
    {
        QPainter painter( &m_imgResult );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_contour );
        painter.drawImage( m_imgOutline.rect(), m_imgOutline, m_imgOutline.rect() );
    }

    // Merge edge shadow
    {
        QPainter painter( &m_imgResult );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_contour );
        painter.drawImage( m_imgEdgeshadow.rect(), m_imgEdgeshadow, m_imgEdgeshadow.rect() );
    }

    // Merge edge highlight
    {
        QPainter painter( &m_imgResult );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        QPainterPath invcontour, invcontour2;
        invcontour.addRect(m_imgEdgehighlight.rect());
        invcontour2 = invcontour.subtracted(m_contour);

        painter.setClipPath( invcontour2 );
        painter.drawImage( m_imgEdgehighlight.rect(), m_imgEdgehighlight, m_imgEdgehighlight.rect() );
    }

    // Merge occlusion
    {
        QPainter painter( &m_imgResult );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_contour );
        painter.drawImage( m_imgOcclusion.rect(), m_imgOcclusion, m_imgOcclusion.rect() );
    }


    //m_imgResult = m_imgOutline;
}

/**************************************************************************************************/
void LsControls::saveResult()
{
    qCDebug( LOG_LSCONTROLS ) << "saveResult()";

//    m_imgOutline.save( m_name + "_outline.png", "png" );
//    m_imgEdgehighlight.save( m_name + "_edge_high.png", "png" );
//    m_imgEdgeshadow.save( m_name + "_edge_shadow.png", "png" );
//    m_imgOcclusion.save( m_name + "_occlusion.png", "png" );
    m_imgResult.save( m_name + ".png", "png" );
}

/**************************************************************************************************/
QImage LsControls::calcVertDerivative( const QImage &a_image, bool dir, const QColor &a_col )
{
    qCDebug( LOG_LSCONTROLS ) << "calcVertDerivative()";

    QImage imagecopy( a_image );
    imagecopy.fill( 0x00000000 );

    int w = imagecopy.width();
    int h = imagecopy.height();

    for( int x = 0; x < w; x++ )
    {
        for( int y = 1; y < h - 1; y++ )
        {
            QRgb *pixelt = ( QRgb * )a_image.scanLine( y - 1 ) + x;
            QRgb *pixelc = ( QRgb * )imagecopy  .scanLine( y ) + x;
            QRgb *pixelb = ( QRgb * )a_image.scanLine( y + 1 ) + x;

            QColor colt( *pixelt );
            QColor colb( *pixelb );
            QColor col = a_col;

            qreal diffr = ( colt.redF()   - colb.redF() ) * ( dir ? 1 : -1 );
            qreal diffg = ( colt.greenF() - colb.greenF() ) * ( dir ? 1 : -1 );
            qreal diffb = ( colt.blueF()  - colb.blueF() ) * ( dir ? 1 : -1 );

            qreal alpha = ( diffr + diffg + diffb ) / 3.0;

            col.setAlphaF( a_col.alphaF() * qMax( 0.0, alpha ) );

            *pixelc = col.rgba();
        }
    }
    return imagecopy;
}

/**************************************************************************************************/
QImage LsControls::calcOmniDerivative( const QImage &a_image, const QColor &a_col )
{
    qCDebug( LOG_LSCONTROLS ) << "calcOmniDerivative()";

    QImage imagecopy( a_image );
    imagecopy.fill( 0x00000000 );

    int w = imagecopy.width();
    int h = imagecopy.height();

    for( int x = 1; x < w-1; x++ )
    {
        for( int y = 1; y < h - 1; y++ )
        {
            QRgb *pixelt = ( QRgb * )a_image.scanLine( y - 1 ) + x;
            QRgb *pixelb = ( QRgb * )a_image.scanLine( y + 1 ) + x;
            QRgb *pixell = ( QRgb * )a_image.scanLine( y     ) + x-1;
            QRgb *pixelr = ( QRgb * )a_image.scanLine( y     ) + x+1;
            QRgb *pixelc = ( QRgb * )a_image.scanLine( y     ) + x;
            QRgb *pixeln = ( QRgb * )imagecopy.scanLine( y     ) + x;

            QColor colt( *pixelt );
            QColor colb( *pixelb );
            QColor coll( *pixell );
            QColor colr( *pixelr );
            QColor colc( *pixelc );

            QColor col = a_col;

            qreal diff = fabs(colt.redF() + colb.redF() + coll.redF() + colr.redF() - 4 * colc.redF())/3;

            col.setAlphaF( a_col.alphaF() * qMin(1.0, qMax( 0.0, diff ) ));

            *pixeln = col.rgba();
        }
    }
    return imagecopy;
}

/**************************************************************************************************/
QImage LsControls::blurImage( const QImage &a_image, double radius )
{
    qCDebug( LOG_LSCONTROLS ) << "blurImage()";

    QImage imagecopy( a_image );
    int rad = radius + 0.5;
    int w = a_image.width();
    int h = a_image.height();

    for( int x = rad; x < w - rad; x++ )
    {
        for( int y = rad; y < h - rad; y++ )
        {
            unsigned long t_a = 0;
            unsigned long t_r = 0;
            unsigned long t_g = 0;
            unsigned long t_b = 0;
            double        t_w = 0.0;

            for( int u = -rad; u <= rad; u++ )
            {
                for( int v = -rad; v <= rad; v++ )
                {
                    double wx = exp( -( ( double )u * u ) / ( ( double )rad * rad ) * 4.0 );
                    double wy = exp( -( ( double )v * v ) / ( ( double )rad * rad ) * 4.0 );
                    QRgb *pixel = ( QRgb * )a_image.scanLine( y + v ) + ( x + u );

                    unsigned char a = ( ( *pixel ) >> 24 ) & 0xff;
                    unsigned char r = ( ( *pixel ) >> 16 ) & 0xff;
                    unsigned char g = ( ( *pixel ) >>  8 ) & 0xff;
                    unsigned char b = ( ( *pixel ) >>  0 ) & 0xff;
                    double w = wx * wy;

                    t_r += r * w;
                    t_g += g * w;
                    t_b += b * w;
                    t_a += a * w;
                    t_w += w;
                }
            }

            QColor col( t_r / t_w, t_g / t_w, t_b / t_w, t_a / t_w );
            QRgb *pixelnew = ( QRgb * )imagecopy.scanLine( y ) + x;

            *pixelnew = col.rgba();
        }
    }

    return imagecopy;
}
