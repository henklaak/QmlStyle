#include "lscontrols.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>
#include <QDir>

Q_LOGGING_CATEGORY( LOG_LSCONTROLS, "LsControls", QtInfoMsg )

const int LsControls::MARGIN    = 16;
const int LsControls::STDHEIGHT = 32;
const int LsControls::STDWIDTH  = 32;

const QColor QCOLOR_WHITE = QColor( 255, 255, 255, 255 );
const QColor QCOLOR_BLACK = QColor( 0,   0,   0, 255 );

const QColor QCOLOR_OUTLINE = QColor( 0,   0,   0,  32 );

const QColor QCOLOR_OUTLINE_HIGHLIGHT = QColor( 255, 255, 255,  50 );
const QColor QCOLOR_OUTLINE_SHADOW = QColor( 0, 0, 0, 192 );
const QColor QCOLOR_OUTLINE_OCCLUSION = QColor( 0, 0, 0, 192 );

const double BLUR_OUTLINE_HIGHLIGHT = 4;
const double BLUR_OUTLINE_SHADOW = 8;
const double BLUR_OUTLINE_OCCLUSION = 8;

const QColor QCOLOR_CONTROL_ENABLED = QColor( 253, 204, 102, 200 );
const QColor QCOLOR_CONTROL_ENABLED_HIGHLIGHT = QColor( 255, 255, 255, 255 );
const QColor QCOLOR_CONTROL_ENABLED_SHADOW = QColor( 0, 0, 0, 64 );
const double BLUR_CONTROL_ENABLED_HIGHLIGHT = 9;
const double BLUR_CONTROL_ENABLED_SHADOW = 12;

const QColor QCOLOR_CONTROL_PRESSED = QColor( 253, 204, 102, 160 );
const QColor QCOLOR_CONTROL_PRESSED_HIGHLIGHT = QColor( 255, 255, 255, 64 );
const QColor QCOLOR_CONTROL_PRESSED_SHADOW = QColor( 0, 0, 0, 32 );
const double BLUR_CONTROL_PRESSED_HIGHLIGHT = 5;
const double BLUR_CONTROL_PRESSED_SHADOW = 5;

const QColor QCOLOR_CONTROL_CHECKED_TRANS = QColor( 255, 0, 0, 0 );
const QColor QCOLOR_CONTROL_CHECKED = QColor( 255, 0, 0, 128 );
const int WIDTH_CONTROL_CHECKED_BACK = 4;
const int BLUR_CONTROL_CHECKED_BACK = 5;
const int BLUR_CONTROL_CHECKED = 1;
const int WIDTH_CONTROL_CHECKED = 1;

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
    initOutlines();

    renderOutlineComponents();
    renderControlEnabledComponents();
    renderControlPressedComponents();
    renderControlCheckedComponents();

    flattenImage();
    saveResult();
}

/**************************************************************************************************/
void LsControls::initImages()
{
    qCDebug( LOG_LSCONTROLS ) << "initImages()";

    initFinalImage();
    m_imgFinalEmpty.fill( 0x00000000 );

    m_imgOutline                        = m_imgFinalEmpty;
    m_imgOutlineHighlight               = m_imgFinalEmpty;
    m_imgOutlineShadow                  = m_imgFinalEmpty;
    m_imgOutlineOcclusion               = m_imgFinalEmpty;

    m_imgControlNormal                  = m_imgFinalEmpty;
    m_imgControlNormalHighlight         = m_imgFinalEmpty;
    m_imgControlNormalShadow            = m_imgFinalEmpty;

    m_imgControlPressed                 = m_imgFinalEmpty;
    m_imgControlPressedHighlight        = m_imgFinalEmpty;
    m_imgControlPressedShadow           = m_imgFinalEmpty;

    m_imgControlChecked                  = m_imgFinalEmpty;

    m_imgFinalEnabledPressedChecked      = m_imgFinalEmpty;
    m_imgFinalEnabledPressedUnchecked    = m_imgFinalEmpty;
    m_imgFinalEnabledUnpressedChecked    = m_imgFinalEmpty;
    m_imgFinalEnabledUnpressedUnchecked  = m_imgFinalEmpty;
    m_imgFinalDisabledPressedChecked     = m_imgFinalEmpty;
    m_imgFinalDisabledPressedUnchecked   = m_imgFinalEmpty;
    m_imgFinalDisabledUnpressedChecked   = m_imgFinalEmpty;
    m_imgFinalDisabledUnpressedUnchecked = m_imgFinalEmpty;
}


/**************************************************************************************************/
void LsControls::renderOutlineComponents()
{
    qCDebug( LOG_LSCONTROLS ) << "renderOutlineComponents()";

    {
        // Prepare empty transparent image
        QPainter painter( &m_imgOutline );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        // Darken hole
        painter.setPen( Qt::NoPen );
        painter.fillPath(
            m_outlinePath,
            QBrush( QCOLOR_OUTLINE ) );
    }
    {
        m_imgOutlineHighlight.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgOutlineHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_outlinePath,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgOutlineHighlight = calcVertDerivative(
                                m_imgOutlineHighlight,
                                false,
                                QCOLOR_OUTLINE_HIGHLIGHT );
    m_imgOutlineHighlight = blurImage(
                                m_imgOutlineHighlight,
                                BLUR_OUTLINE_HIGHLIGHT );

    {
        m_imgOutlineShadow.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgOutlineShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_outlinePath,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgOutlineShadow = calcVertDerivative(
                             m_imgOutlineShadow,
                             true,
                             QCOLOR_OUTLINE_SHADOW );
    m_imgOutlineShadow = blurImage(
                             m_imgOutlineShadow,
                             BLUR_OUTLINE_SHADOW );

    {
        m_imgOutlineOcclusion.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgOutlineOcclusion );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_outlinePath,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgOutlineOcclusion = calcOmniDerivative(
                                m_imgOutlineOcclusion,
                                QCOLOR_OUTLINE_OCCLUSION );
    m_imgOutlineOcclusion = blurImage(
                                m_imgOutlineOcclusion,
                                BLUR_OUTLINE_OCCLUSION );
}

/**************************************************************************************************/
void LsControls::renderControlEnabledComponents()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControlEnabledComponents()";

    {
        // Prepare empty transparent image
        QPainter painter( &m_imgControlNormal );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        painter.setPen( Qt::NoPen );
        painter.fillPath(
            m_controlPathOuter,
            QCOLOR_CONTROL_ENABLED );
    }

    {
        m_imgControlNormalHighlight.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgControlNormalHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_controlPathInner,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgControlNormalHighlight = calcVertDerivative(
                                      m_imgControlNormalHighlight,
                                      true,
                                      QCOLOR_CONTROL_ENABLED_HIGHLIGHT );
    m_imgControlNormalHighlight = blurImage(
                                      m_imgControlNormalHighlight,
                                      BLUR_CONTROL_ENABLED_HIGHLIGHT );
    {
        m_imgControlNormalShadow.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgControlNormalShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_controlPathInner,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgControlNormalShadow = calcVertDerivative(
                                   m_imgControlNormalShadow,
                                   false,
                                   QCOLOR_CONTROL_ENABLED_SHADOW );
    m_imgControlNormalShadow = blurImage(
                                   m_imgControlNormalShadow,
                                   BLUR_CONTROL_ENABLED_SHADOW );
}

/**************************************************************************************************/
void LsControls::renderControlPressedComponents()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControlPressedComponents()";

    {
        // Prepare empty transparent image
        QPainter painter( &m_imgControlPressed );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

        painter.setPen( Qt::NoPen );
        painter.fillPath(
            m_controlPathOuter,
            QCOLOR_CONTROL_PRESSED );
    }

    {
        m_imgControlPressedHighlight.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgControlPressedHighlight );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_controlPathInner,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgControlPressedHighlight = calcVertDerivative(
                                       m_imgControlPressedHighlight,
                                       true,
                                       QCOLOR_CONTROL_PRESSED_HIGHLIGHT );
    m_imgControlPressedHighlight = blurImage(
                                       m_imgControlPressedHighlight,
                                       BLUR_CONTROL_PRESSED_HIGHLIGHT );

    {
        m_imgControlPressedShadow.fill( QCOLOR_WHITE );

        QPainter painter( &m_imgControlPressedShadow );
        painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter.fillPath(
            m_controlPathInner,
            QBrush( QCOLOR_BLACK ) );
    }

    m_imgControlPressedShadow = calcVertDerivative(
                                    m_imgControlPressedShadow,
                                    false,
                                    QCOLOR_CONTROL_PRESSED_SHADOW );
    m_imgControlPressedShadow = blurImage(
                                    m_imgControlPressedShadow,
                                    BLUR_CONTROL_PRESSED_SHADOW );
}

/**************************************************************************************************/
void LsControls::renderControlCheckedComponents()
{
    qCDebug( LOG_LSCONTROLS ) << "renderControlCheckedComponents()";

    {
        m_imgControlChecked.fill( QCOLOR_CONTROL_CHECKED_TRANS );

        // Prepare empty transparent image
        QPainter painter( &m_imgControlChecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );

        QPen stroker(
            QCOLOR_CONTROL_CHECKED,
            WIDTH_CONTROL_CHECKED_BACK );
        painter.strokePath(
            m_controlPathOuter,
            stroker );
        painter.fillPath(
            m_controlPathChecked, QCOLOR_CONTROL_CHECKED );
    }
    m_imgControlChecked = blurImage(
                              m_imgControlChecked,
                              BLUR_CONTROL_CHECKED_BACK );
    {
        // Prepare empty transparent image
        QPainter painter( &m_imgControlChecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );

        painter.setClipPath( m_controlPathOuter );
        QPen stroker(
            QCOLOR_CONTROL_CHECKED,
            WIDTH_CONTROL_CHECKED );
        painter.strokePath(
            m_controlPathOuter,
            stroker );
    }
    m_imgControlChecked = blurImage(
                              m_imgControlChecked ,
                              BLUR_CONTROL_CHECKED );
}

/**************************************************************************************************/
void LsControls::flattenImage()
{
    qCDebug( LOG_LSCONTROLS ) << "flattenImage()";

    //////////////////////////////////////

    {
        // Merge edge shadow
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage(
            m_imgOutline.rect(),
            m_imgOutline,
            m_imgOutline.rect() );
    }
    {
        // Merge edge shadow
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage(
            m_imgOutlineShadow.rect(),
            m_imgOutlineShadow,
            m_imgOutlineShadow.rect() );
    }
    {
        // Merge edge highlight
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );

        QPainterPath invcontour, invcontour2;
        invcontour.addRect( m_imgOutlineHighlight.rect() );
        invcontour2 = invcontour.subtracted( m_outlinePath );

        painter.setClipPath( invcontour2 );
        painter.drawImage(
            m_imgOutlineHighlight.rect()
            , m_imgOutlineHighlight,
            m_imgOutlineHighlight.rect() );
    }
    {
        // Merge occlusion
        QPainter painter( &m_imgFinalEmpty );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_outlinePath );
        painter.drawImage(
            m_imgOutlineOcclusion.rect(),
            m_imgOutlineOcclusion,
            m_imgOutlineOcclusion.rect() );
    }

    //////////////////////////////////////

    m_imgFinalEnabledUnpressedUnchecked = m_imgFinalEmpty;

    {
        // Merge control
        QPainter painter( &m_imgFinalEnabledUnpressedUnchecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.drawImage(
            m_imgControlNormal.rect(),
            m_imgControlNormal,
            m_imgControlNormal.rect() );
    }
    {
        // Merge control highlight
        QPainter painter( &m_imgFinalEnabledUnpressedUnchecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPathOuter );
        painter.drawImage(
            m_imgControlNormalHighlight.rect(),
            m_imgControlNormalHighlight,
            m_imgControlNormalHighlight.rect() );
    }
    {
        // Merge control shadow
        QPainter painter( &m_imgFinalEnabledUnpressedUnchecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPathOuter );
        painter.drawImage(
            m_imgControlNormalShadow.rect(),
            m_imgControlNormalShadow,
            m_imgControlNormalShadow.rect() );
    }

    //////////////////////////////////////

    m_imgFinalEnabledPressedUnchecked = m_imgFinalEmpty;

    {
        // Merge control
        QPainter painter( &m_imgFinalEnabledPressedUnchecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.drawImage(
            m_imgControlPressed.rect(),
            m_imgControlPressed,
            m_imgControlPressed.rect() );
    }
    {
        // Merge control highlight
        QPainter painter( &m_imgFinalEnabledPressedUnchecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPathOuter );
        painter.drawImage(
            m_imgControlPressedHighlight.rect(),
            m_imgControlPressedHighlight,
            m_imgControlPressedHighlight.rect() );
    }
    {
        // Merge control shadow
        QPainter painter( &m_imgFinalEnabledPressedUnchecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.setClipPath( m_controlPathOuter );
        painter.drawImage(
            m_imgControlPressedShadow.rect(),
            m_imgControlPressedShadow,
            m_imgControlPressedShadow.rect() );
    }

    //////////////////////////////////////

    m_imgFinalEnabledPressedChecked = m_imgFinalEnabledPressedUnchecked;

    {
        // Merge control
        QPainter painter( &m_imgFinalEnabledPressedChecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.drawImage( m_imgControlChecked.rect(),
                           m_imgControlChecked,
                           m_imgControlChecked.rect() );
    }

    //////////////////////////////////////

    m_imgFinalEnabledUnpressedChecked = m_imgFinalEnabledUnpressedUnchecked;

    {
        // Merge control
        QPainter painter( &m_imgFinalEnabledUnpressedChecked );
        painter.setRenderHints(
            QPainter::Antialiasing |
            QPainter::HighQualityAntialiasing );
        painter.drawImage(
            m_imgControlChecked.rect(),
            m_imgControlChecked,
            m_imgControlChecked.rect() );
    }


    m_imgFinalDisabledPressedChecked     = m_imgFinalEmpty;
    m_imgFinalDisabledUnpressedChecked   = m_imgFinalEmpty;
    m_imgFinalDisabledPressedUnchecked   = m_imgFinalEmpty;
    m_imgFinalDisabledUnpressedUnchecked = m_imgFinalEmpty;

}

/**************************************************************************************************/
void LsControls::saveResult()
{
    qCDebug( LOG_LSCONTROLS ) << "saveResult()";

    QDir base( "/home/henklaak/Projects/QmlStyleLaaksoft/src/libs/LsControlsPlugin/Images" );

    m_imgFinalEnabledPressedChecked.save(
        base.absoluteFilePath( m_name + "_enabled_pressed_checked.png" ) );
    m_imgFinalEnabledPressedUnchecked.save(
        base.absoluteFilePath( m_name + "_enabled_pressed_unchecked.png" ) );

    m_imgFinalEnabledUnpressedChecked.save(
        base.absoluteFilePath( m_name + "_enabled_unpressed_checked.png" ) );
    m_imgFinalEnabledUnpressedUnchecked.save(
        base.absoluteFilePath( m_name + "_enabled_unpressed_unchecked.png" ) );

    m_imgFinalDisabledPressedChecked.save(
        base.absoluteFilePath( m_name + "_disabled_pressed_checked.png" ) );
    m_imgFinalDisabledPressedUnchecked.save(
        base.absoluteFilePath( m_name + "_disabled_pressed_unchecked.png" ) );

    m_imgFinalDisabledUnpressedChecked.save(
        base.absoluteFilePath( m_name + "_disabled_unpressed_checked.png" ) );
    m_imgFinalDisabledUnpressedUnchecked.save(
        base.absoluteFilePath( m_name + "_disabled_unpressed_unchecked.png" ) );
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

/**************************************************************************************************/
QPainterPath LsControls::getOutline( int a_x,
                                     int a_y,
                                     int a_width,
                                     int a_height,
                                     int a_shrink,
                                     int a_radius1,
                                     int a_radius2,
                                     int a_radius3,
                                     int a_radius4 )
{
    qCDebug( LOG_LSCONTROLS ) << "getOutline()";

    QPainterPath path;

    QPointF topLeft( a_x + a_shrink, a_y + a_shrink );
    QPointF topRight( a_x + a_width - a_shrink, a_y + a_shrink );
    QPointF botLeft( a_x + a_shrink, a_y + a_height - a_shrink );
    QPointF botRight( a_x + a_width - a_shrink, a_y + a_height - a_shrink );

    QRectF topLeftArc  = QRectF(
                             topLeft  + QPointF( 0, 0 ),
                             QSizeF( 2 * ( a_radius1 - a_shrink ), 2 * ( a_radius1 - a_shrink ) ) );
    QRectF topRightArc = QRectF(
                             topRight + QPointF( -2 * ( a_radius2 - a_shrink ), 0 ),
                             QSizeF( 2 * ( a_radius2 - a_shrink ), 2 * ( a_radius2 - a_shrink ) ) );
    QRectF botRightArc = QRectF(
                             botRight + QPointF( -2 * ( a_radius3 - a_shrink ), -2 * ( a_radius3 - a_shrink ) ),
                             QSizeF( 2 * ( a_radius3 - a_shrink ), 2 * ( a_radius3 - a_shrink ) ) );
    QRectF botLeftArc  = QRectF(
                             botLeft  + QPointF( 0, -2 * ( a_radius4 - a_shrink ) ),
                             QSizeF( 2 * ( a_radius4 - a_shrink ), 2 * ( a_radius4 - a_shrink ) ) );

    QPointF top1   = topLeft  + QPointF( ( a_radius1 - a_shrink ), 0 );
    QPointF top2   = topRight + QPointF( -( a_radius2 - a_shrink ), 0 );
    QPointF right1 = topRight + QPointF( 0, ( a_radius2  - a_shrink ) );
    QPointF right2 = botRight + QPointF( 0, -( a_radius3  - a_shrink ) );
    QPointF bot1   = botRight + QPointF( -( a_radius3 - a_shrink ), 0 );
    QPointF bot2   = botLeft  + QPointF( ( a_radius4 - a_shrink ), 0 );
    QPointF left1  = botLeft  + QPointF( 0, -( a_radius4 - a_shrink ) );
    QPointF left2  = topLeft  + QPointF( 0, ( a_radius1 - a_shrink ) );

    path.moveTo( top1 );
    path.lineTo( top2 );
    path.arcTo( topRightArc, 90, -90 );
    path.lineTo( right1 );
    path.lineTo( right2 );
    path.arcTo( botRightArc, 0, -90 );
    path.lineTo( bot1 );
    path.lineTo( bot2 );
    path.arcTo( botLeftArc, -90, -90 );
    path.lineTo( left1 );
    path.lineTo( left2 );
    path.arcTo( topLeftArc, -180, -90 );
    path.lineTo( top1 );
    path.closeSubpath();

    return path;
}
