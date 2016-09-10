#include "lscontrols.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>
#include <QDir>

Q_LOGGING_CATEGORY( LOG_LSCONTROLS, "LsControls", QtInfoMsg )


/**************************************************************************************************/
LsControls::LsControls( const QString &a_name, QObject *a_parent )
    : QObject( a_parent )
    , m_name( a_name )
{
    qCDebug( LOG_LSCONTROLS ) << "LsControls()" << a_name;
}

/**************************************************************************************************/
LsControls::~LsControls()
{
    qCDebug( LOG_LSCONTROLS ) << "~LsControls()";
}

/**************************************************************************************************/
void LsControls::render()
{
    qCInfo( LOG_LSCONTROLS ) << "render()" << m_name;

    initImages();
    initOutline();
    initControl();

    renderOutline();
    renderControlNormal();
    renderControlPressed();

    flattenImage();
    saveResult();
}

/**************************************************************************************************/
void LsControls::initImages()
{
    qCDebug( LOG_LSCONTROLS ) << "initImages()";

    initFinalImage();
    m_imgFinalEmpty.fill( 0x00000000 );

    m_imgOutline          = m_imgFinalEmpty;
    m_imgOutlineHighlight = m_imgFinalEmpty;
    m_imgOutlineShadow    = m_imgFinalEmpty;
    m_imgOutlineOcclusion = m_imgFinalEmpty;

    m_imgFinalNormal      = m_imgFinalEmpty;
    m_imgControlNormal          = m_imgFinalEmpty;
    m_imgControlNormalHighlight = m_imgFinalEmpty;
    m_imgControlNormalShadow    = m_imgFinalEmpty;

    m_imgFinalPressed            = m_imgFinalEmpty;
    m_imgControlPressed          = m_imgFinalEmpty;
    m_imgControlPressedHighlight = m_imgFinalEmpty;
    m_imgControlPressedShadow    = m_imgFinalEmpty;

    m_imgFinalDisabled           = m_imgFinalEmpty;
}


/**************************************************************************************************/
void LsControls::renderOutline()
{
    qCDebug( LOG_LSCONTROLS ) << "renderOutline()";

    {
        // Prepare empty transparent image
        QPainter painter( &m_imgOutline );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        // Darken hole
        painter.setPen( Qt::NoPen );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 32 ) ) );
    }
    {
        m_imgOutlineHighlight.fill( 0xffffffff );

        QPainter painter( &m_imgOutlineHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOutlineHighlight = calcVertDerivative( m_imgOutlineHighlight, false, QColor( 255, 255, 255,
                            50 ) );
    m_imgOutlineHighlight = blurImage( m_imgOutlineHighlight, 4 );

    {
        m_imgOutlineShadow.fill( 0xffffffff );

        QPainter painter( &m_imgOutlineShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOutlineShadow = calcVertDerivative( m_imgOutlineShadow, true, QColor( 0, 0, 0, 192 ) );
    m_imgOutlineShadow = blurImage( m_imgOutlineShadow, 8 );

    {
        m_imgOutlineOcclusion.fill( 0xffffffff );

        QPainter painter( &m_imgOutlineOcclusion );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_outlinePath, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgOutlineOcclusion = calcOmniDerivative( m_imgOutlineOcclusion, QColor( 0, 0, 0, 192 ) );
    m_imgOutlineOcclusion = blurImage( m_imgOutlineOcclusion, 8 );
}

/**************************************************************************************************/
void LsControls::renderControlNormal()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControl()";

    {
        // Prepare empty transparent image
        QPainter painter( &m_imgControlNormal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        painter.setPen( Qt::NoPen );
        painter.fillPath( m_controlPath, QColor( 253, 204, 102, 255 ) );
    }

    {
        m_imgControlNormalHighlight.fill( 0xffffffff );

        QPainter painter( &m_imgControlNormalHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_controlPath2, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgControlNormalHighlight = calcVertDerivative( m_imgControlNormalHighlight, true, QColor( 255,
                                  255, 255, 255 ) );
    m_imgControlNormalHighlight = blurImage( m_imgControlNormalHighlight, 9 );
    {
        m_imgControlNormalShadow.fill( 0xffffffff );

        QPainter painter( &m_imgControlNormalShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_controlPath2, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgControlNormalShadow = calcVertDerivative( m_imgControlNormalShadow, false, QColor( 0, 0, 0,
                               64 ) );
    m_imgControlNormalShadow = blurImage( m_imgControlNormalShadow, 12 );
}

/**************************************************************************************************/
void LsControls::renderControlPressed()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControlPressed()";

    {
        // Prepare empty transparent image
        QPainter painter( &m_imgControlPressed );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        painter.setPen( Qt::NoPen );
        painter.fillPath( m_controlPath, QColor( 253, 204, 102, 224 ) );
    }

    {
        m_imgControlPressedHighlight.fill( 0xffffffff );

        QPainter painter( &m_imgControlPressedHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_controlPath2, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgControlPressedHighlight = calcVertDerivative( m_imgControlPressedHighlight, true, QColor( 255,
                                   255, 255, 64 ) );
    m_imgControlPressedHighlight = blurImage( m_imgControlPressedHighlight, 5 );

    {
        m_imgControlPressedShadow.fill( 0xffffffff );

        QPainter painter( &m_imgControlPressedShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath( m_controlPath2, QBrush( QColor( 0, 0, 0, 255 ) ) );
    }

    m_imgControlPressedShadow = calcVertDerivative( m_imgControlPressedShadow, false, QColor( 0, 0, 0,
                                32 ) );
    m_imgControlPressedShadow = blurImage( m_imgControlPressedShadow, 5 );
}

/**************************************************************************************************/
void LsControls::flattenImage()
{
    qCDebug( LOG_LSCONTROLS ) << "flattenImage()";
    QDir base( "/home/henklaak/Projects/QmlStyleLaaksoft/src/libs/LsControlsPlugin/Images" );

    // Merge edge shadow
    if( 1 )
    {
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage( m_imgOutline.rect(), m_imgOutline, m_imgOutline.rect() );
    }

    // Merge edge shadow
    if( 1 )
    {
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage( m_imgOutlineShadow.rect(), m_imgOutlineShadow, m_imgOutlineShadow.rect() );
    }

    // Merge edge highlight
    if( 1 )
    {
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        QPainterPath invcontour, invcontour2;
        invcontour.addRect( m_imgOutlineHighlight.rect() );
        invcontour2 = invcontour.subtracted( m_outlinePath );

        painter.setClipPath( invcontour2 );
        painter.drawImage( m_imgOutlineHighlight.rect(), m_imgOutlineHighlight,
                           m_imgOutlineHighlight.rect() );
    }

    // Merge occlusion
    if( 1 )
    {
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage( m_imgOutlineOcclusion.rect(), m_imgOutlineOcclusion,
                           m_imgOutlineOcclusion.rect() );
    }

    //////////////////////////////////////

    m_imgFinalNormal = m_imgFinalEmpty;

    // Merge control
    if( 1 )
    {
        QPainter painter( &m_imgFinalNormal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.drawImage( m_imgControlNormal.rect(), m_imgControlNormal, m_imgControlNormal.rect() );
    }

    // Merge control highlight
    if( 1 )
    {
        QPainter painter( &m_imgFinalNormal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPath );
        painter.drawImage( m_imgControlNormalHighlight.rect(), m_imgControlNormalHighlight,
                           m_imgControlNormalHighlight.rect() );
    }

    // Merge control shadow
    if( 1 )
    {
        QPainter painter( &m_imgFinalNormal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPath );
        painter.drawImage( m_imgControlNormalShadow.rect(), m_imgControlNormalShadow,
                           m_imgControlNormalShadow.rect() );
    }

    //////////////////////////////////////

    m_imgFinalPressed = m_imgFinalEmpty;

    // Merge control
    if( 1 )
    {
        QPainter painter( &m_imgFinalPressed );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.drawImage( m_imgControlPressed.rect(), m_imgControlPressed, m_imgControlPressed.rect() );
    }

    // Merge control highlight
    if( 1 )
    {
        QPainter painter( &m_imgFinalPressed );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPath );
        painter.drawImage( m_imgControlPressedHighlight.rect(), m_imgControlPressedHighlight,
                           m_imgControlPressedHighlight.rect() );
    }

    // Merge control shadow
    if( 1 )
    {
        QPainter painter( &m_imgFinalPressed );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPath );
        painter.drawImage( m_imgControlPressedShadow.rect(), m_imgControlPressedShadow,
                           m_imgControlPressedShadow.rect() );
    }

    //////////////////////////////////////

    m_imgFinalDisabled = m_imgFinalEmpty;

}

/**************************************************************************************************/
void LsControls::saveResult()
{
    qCDebug( LOG_LSCONTROLS ) << "saveResult()";

    QDir base( "/home/henklaak/Projects/QmlStyleLaaksoft/src/libs/LsControlsPlugin/Images" );
    m_imgFinalNormal.save( base.absoluteFilePath( m_name + "_enabled_unpressed_checked.png" ) );
    m_imgFinalNormal.save( base.absoluteFilePath( m_name + "_enabled_unpressed_unchecked.png" ) );

    m_imgFinalPressed.save( base.absoluteFilePath( m_name + "_enabled_pressed_checked.png" ) );
    m_imgFinalPressed.save( base.absoluteFilePath( m_name + "_enabled_pressed_unchecked.png" ) );

    m_imgFinalDisabled.save( base.absoluteFilePath( m_name + "_disabled_unpressed_checked.png" ) );
    m_imgFinalDisabled.save( base.absoluteFilePath( m_name + "_disabled_unpressed_unchecked.png" ) );

    m_imgFinalDisabled.save( base.absoluteFilePath( m_name + "_disabled_pressed_checked.png" ) );
    m_imgFinalDisabled.save( base.absoluteFilePath( m_name + "_disabled_pressed_unchecked.png" ) );
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

    for( int x = 1; x < w - 1; x++ )
    {
        for( int y = 1; y < h - 1; y++ )
        {
            QRgb *pixelt = ( QRgb * )a_image.scanLine( y - 1 ) + x;
            QRgb *pixelb = ( QRgb * )a_image.scanLine( y + 1 ) + x;
            QRgb *pixell = ( QRgb * )a_image.scanLine( y ) + x - 1;
            QRgb *pixelr = ( QRgb * )a_image.scanLine( y ) + x + 1;
            QRgb *pixelc = ( QRgb * )a_image.scanLine( y ) + x;
            QRgb *pixeln = ( QRgb * )imagecopy.scanLine( y ) + x;

            QColor colt( *pixelt );
            QColor colb( *pixelb );
            QColor coll( *pixell );
            QColor colr( *pixelr );
            QColor colc( *pixelc );

            QColor col = a_col;

            qreal diff = fabs( colt.redF() + colb.redF() + coll.redF() + colr.redF() - 4 * colc.redF() ) / 3;

            col.setAlphaF( a_col.alphaF() * qMin( 1.0, qMax( 0.0, diff ) ) );

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
