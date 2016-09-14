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

    m_imgFinalEmpty = QImage( MARGIN + 2 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsSliderIndicator::initOutlines()
{
    qCDebug( LOG_LSSLIDERINDICATOR ) << "initOutline()";

    m_controlPathOuter = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                2 * STDWIDTH,
                                2 * STDHEIGHT,
                                2,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT );
    m_controlPathInner = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                2 * STDWIDTH,
                                2 * STDHEIGHT,
                                4,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT );
}
