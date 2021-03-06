#include "lstoolbuttonboth.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSTOOLBUTTONBOTH, "LsToolButtonBoth", QtWarningMsg )


/**************************************************************************************************/
LsToolButtonBoth::LsToolButtonBoth( QObject *a_parent )
    : LsControls( "ToolButtonBoth", a_parent )
{
    qCDebug( LOG_LSTOOLBUTTONBOTH ) << "LsToolButtonBoth()";
}

/**************************************************************************************************/
LsToolButtonBoth::~LsToolButtonBoth()
{
    qCDebug( LOG_LSTOOLBUTTONBOTH ) << "~LsToolButtonBoth()";
}

/**************************************************************************************************/
void LsToolButtonBoth::initFinalImage()
{
    qCDebug( LOG_LSTOOLBUTTONBOTH ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 8 * STDWIDTH + MARGIN,
                              MARGIN + 3 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsToolButtonBoth::initOutlines()
{
    qCDebug( LOG_LSTOOLBUTTONBOTH ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                8 * STDWIDTH,
                                3 * STDHEIGHT,
                                0,
                                STDHEIGHT*1.5,
                                STDHEIGHT*1.5,
                                STDHEIGHT*1.5,
                                STDHEIGHT*1.5);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     2,
                                     STDHEIGHT*1.5,
                                     STDHEIGHT*1.5,
                                     STDHEIGHT*1.5,
                                     STDHEIGHT*1.5);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     4,
                                     STDHEIGHT*1.5,
                                     STDHEIGHT*1.5,
                                     STDHEIGHT*1.5,
                                     STDHEIGHT*1.5);
}
