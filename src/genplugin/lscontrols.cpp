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
    renderOutlineHighlight();
    renderOutlineShadow();
    renderOutlineOcclusion();

    initControl();
    renderControl();
    renderControlHighlight();
    renderControlShadow();

    flattenImage();
    saveResult();
}

/**************************************************************************************************/
void LsControls::initImages()
{
    qCDebug( LOG_LSCONTROLS ) << "initImages()";

    initFinalImage();
    m_imgFinal.fill( 0x00000000);

    m_imgOutline       = m_imgFinal;
    m_imgOutlineHighlight = m_imgFinal;
    m_imgOutlineShadow    = m_imgFinal;
    m_imgOutlineOcclusion     = m_imgFinal;

    m_imgControl = m_imgFinal;
    m_imgControlHighlight = m_imgFinal;
    m_imgControlShadow= m_imgFinal;

//    m_imgFinal.fill( 0xff2f3356 );
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
    painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 32 ) ) );
}

/**************************************************************************************************/
void LsControls::renderOutlineHighlight()
{
    qCDebug( LOG_LSCONTROLS ) << "renderEdgeHighlight()";
    {
        m_imgOutlineHighlight.fill( 0xffffffff );

        QPainter painter( &m_imgOutlineHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOutlineHighlight = calcVertDerivative( m_imgOutlineHighlight, false, QColor( 255, 255, 255, 64) );
    m_imgOutlineHighlight = blurImage( m_imgOutlineHighlight, 4 );
}

/**************************************************************************************************/
void LsControls::renderOutlineShadow()
{
    qCDebug( LOG_LSCONTROLS ) << "renderEdgeShadow()";
    {
        m_imgOutlineShadow.fill( 0xffffffff );

        QPainter painter( &m_imgOutlineShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOutlineShadow = calcVertDerivative( m_imgOutlineShadow, true, QColor( 0, 0, 0, 192) );
    m_imgOutlineShadow = blurImage( m_imgOutlineShadow, 8 );
}

/**************************************************************************************************/
void LsControls::renderOutlineOcclusion()
{
    qCDebug( LOG_LSCONTROLS ) << "renderOcclusion()";
    {
        m_imgOutlineOcclusion.fill( 0xffffffff );

        QPainter painter( &m_imgOutlineOcclusion );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOutlineOcclusion = calcOmniDerivative( m_imgOutlineOcclusion, QColor( 0, 0, 0, 192) );
    m_imgOutlineOcclusion = blurImage( m_imgOutlineOcclusion, 8 );
}

/**************************************************************************************************/
void LsControls::renderControl()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControl()";

    // Prepare empty transparent image
    QPainter painter( &m_imgControl );
    painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

    QRectF rect = m_controlPath.toFillPolygon().boundingRect();

    QLinearGradient gradient(rect.topLeft(), rect.bottomLeft());
    gradient.setColorAt(0, QColor(160,160,220,192));
    gradient.setColorAt(1, QColor(120,120,200,128));

    painter.setPen( Qt::NoPen );
    painter.fillPath( m_controlPath, gradient);
}

/**************************************************************************************************/
void LsControls::renderControlHighlight()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControlHighlight()";
    {
        m_imgControlHighlight.fill( 0xffffffff );

        QPainter painter( &m_imgControlHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_controlPath2, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgControlHighlight = calcVertDerivative( m_imgControlHighlight, true, QColor( 255, 255, 255, 255) );
    m_imgControlHighlight = blurImage( m_imgControlHighlight, 9);
}

/**************************************************************************************************/
void LsControls::renderControlShadow()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControlHighlight()";
    {
        m_imgControlShadow.fill( 0xffffffff );

        QPainter painter( &m_imgControlShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_controlPath2, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgControlShadow = calcVertDerivative( m_imgControlShadow, false, QColor( 0,0,0, 255) );
    m_imgControlShadow = blurImage( m_imgControlShadow, 12 );
}

/**************************************************************************************************/
void LsControls::flattenImage()
{
    qCDebug( LOG_LSCONTROLS ) << "flattenImage()";

    // Merge edge shadow
    {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage( m_imgOutline.rect(), m_imgOutline, m_imgOutline.rect() );
    }

    // Merge edge shadow
    {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage( m_imgOutlineShadow.rect(), m_imgOutlineShadow, m_imgOutlineShadow.rect() );
    }

    // Merge edge highlight
    {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        QPainterPath invcontour, invcontour2;
        invcontour.addRect(m_imgOutlineHighlight.rect());
        invcontour2 = invcontour.subtracted(m_outlinePath);

        painter.setClipPath( invcontour2 );
        painter.drawImage( m_imgOutlineHighlight.rect(), m_imgOutlineHighlight, m_imgOutlineHighlight.rect() );
    }

    // Merge occlusion
    {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage( m_imgOutlineOcclusion.rect(), m_imgOutlineOcclusion, m_imgOutlineOcclusion.rect() );
    }

    // Merge control
    {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.drawImage( m_imgControl.rect(), m_imgControl, m_imgControl.rect() );
    }

    // Merge control highlight
    if (1) {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPath );
        painter.drawImage( m_imgControlHighlight.rect(), m_imgControlHighlight, m_imgControlHighlight.rect() );
    }

    // Merge control shadow
    if (1) {
        QPainter painter( &m_imgFinal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPath );
        painter.drawImage( m_imgControlShadow.rect(), m_imgControlShadow, m_imgControlShadow.rect() );
    }

}

/**************************************************************************************************/
void LsControls::saveResult()
{
    qCDebug( LOG_LSCONTROLS ) << "saveResult()";

//    m_imgOutline.save( m_name + "_outline.png", "png" );
//    m_imgOutlineHighlight.save( m_name + "_edge_high.png", "png" );
//    m_imgOutlineShadow.save( m_name + "_edge_shadow.png", "png" );
//    m_imgOutlineOcclusion.save( m_name + "_occlusion.png", "png" );
    m_imgFinal.save( m_name + ".png", "png" );
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
