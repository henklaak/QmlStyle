#include "lstoolbuttonleft.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSTOOLBUTTONLEFT, "LsToolButtonLeft", QtWarningMsg )


/**************************************************************************************************/
LsToolButtonLeft::LsToolButtonLeft( QObject *a_parent )
    : LsControls( "ToolButtonLeft", a_parent )
{
    qCDebug( LOG_LSTOOLBUTTONLEFT ) << "LsToolButtonLeft()";
}

/**************************************************************************************************/
LsToolButtonLeft::~LsToolButtonLeft()
{
    qCDebug( LOG_LSTOOLBUTTONLEFT ) << "~LsToolButtonLeft()";
}

/**************************************************************************************************/
void LsToolButtonLeft::initFinalImage()
{
    qCDebug( LOG_LSTOOLBUTTONLEFT ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 4 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsToolButtonLeft::initOutlines()
{
    qCDebug( LOG_LSTOOLBUTTONLEFT ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                STDHEIGHT,
                                0,
                                0,
                                STDHEIGHT);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     2,
                                     STDHEIGHT,
                                     0,
                                     0,
                                     STDHEIGHT);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     4,
                                     STDHEIGHT,
                                     0,
                                     0,
                                     STDHEIGHT);
}
