#include "lsslider.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSSLIDER, "LsSlider", QtWarningMsg )


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

    m_imgFinalEmpty = QImage( MARGIN + 8 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );}

/**************************************************************************************************/
void LsSlider::initOutlines()
{
    qCDebug( LOG_LSSLIDER ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                8 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT );}
