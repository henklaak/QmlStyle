#include "lsslider.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSSLIDER, "LsSlider", QtDebugMsg )


/**************************************************************************************************/
LsSlider::LsSlider( QObject *a_parent )
    : LsControls( "Slider", a_parent )
{
    qCDebug( LOG_LSSLIDER ) << "LsSlider()";
}

/**************************************************************************************************/
LsSlider::~LsSlider()
{
    qCDebug( LOG_LSSLIDER ) << "~LsSlider()";
}

/**************************************************************************************************/
void LsSlider::initFinalImage()
{
    qCDebug( LOG_LSSLIDER ) << "initFinalImage()";

    m_imgFinal = QImage( 200+64, 32+64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsSlider::initOutline()
{
    qCDebug( LOG_LSSLIDER ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 200, 32 ), 16, 16 );
}

/**************************************************************************************************/
void LsSlider::initControl()
{
    qCDebug( LOG_LSSLIDER ) << "initControl()";

    m_controlPath = QPainterPath();
    m_controlPath.addRoundedRect( QRectF( 34, 34, 28, 28 ), 14, 14 );
}

