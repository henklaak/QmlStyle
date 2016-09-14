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

    m_imgFinalEmpty = QImage( MARGIN + 8 * STDWIDTH + MARGIN,
                              MARGIN + 3 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsToolButtonLeft::initOutlines()
{
    qCDebug( LOG_LSTOOLBUTTONLEFT ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                8 * STDWIDTH,
                                3 * STDHEIGHT,
                                0,
                                STDHEIGHT*1.5,
                                0,
                                0,
                                STDHEIGHT*1.5);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     2,
                                     STDHEIGHT*1.5,
                                     0,
                                     0,
                                     STDHEIGHT*1.5);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     4,
                                     STDHEIGHT*1.5,
                                     0,
                                     0,
                                     STDHEIGHT*1.5);
}
