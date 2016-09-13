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

    m_imgFinalEmpty = QImage( MARGIN + 4 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsToolButtonBoth::initOutlines()
{
    qCDebug( LOG_LSTOOLBUTTONBOTH ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     2,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     4,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT);
}
