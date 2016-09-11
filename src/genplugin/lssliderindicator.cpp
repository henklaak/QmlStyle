#include "lssliderindicator.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSSLIDERINDICATOR, "LsSliderIndicator", QtWarningMsg )


/**************************************************************************************************/
LsSliderIndicator::LsSliderIndicator( QObject *a_parent )
    : LsControls( "SliderIndicator", a_parent )
{
    qCDebug( LOG_LSSLIDERINDICATOR ) << "LsSliderIndicator()";
}

/**************************************************************************************************/
LsSliderIndicator::~LsSliderIndicator()
{
    qCDebug( LOG_LSSLIDERINDICATOR ) << "~LsSliderIndicator()";
}

/**************************************************************************************************/
void LsSliderIndicator::initFinalImage()
{
    qCDebug( LOG_LSSLIDERINDICATOR ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( 32 + 64, 32 + 64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsSliderIndicator::initOutline()
{
    qCDebug( LOG_LSSLIDERINDICATOR ) << "initOutline()";

    m_outlinePath = QPainterPath();
    //m_outlinePath.addRoundedRect( QRectF( 32, 32, 200, 32 ), 16, 16 );
}

/**************************************************************************************************/
void LsSliderIndicator::initControl()
{
    qCDebug( LOG_LSSLIDERINDICATOR ) << "initControl()";

    m_controlPathOuter = QPainterPath();
    m_controlPathOuter.addRoundedRect( QRectF( 34, 34, 28, 28 ), 14, 14 );

    m_controlPathInner = QPainterPath();
    m_controlPathInner.addRoundedRect( QRectF( 37, 37, 22, 22 ), 11, 11 );
}
