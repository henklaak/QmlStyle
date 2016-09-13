#include "lstoolbuttonright.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSTOOLBUTTONRIGHT, "LsToolButtonRight", QtWarningMsg )


/**************************************************************************************************/
LsToolButtonRight::LsToolButtonRight( QObject *a_parent )
    : LsControls( "ToolButtonRight", a_parent )
{
    qCDebug( LOG_LSTOOLBUTTONRIGHT ) << "LsToolButtonRight()";
}

/**************************************************************************************************/
LsToolButtonRight::~LsToolButtonRight()
{
    qCDebug( LOG_LSTOOLBUTTONRIGHT ) << "~LsToolButtonRight()";
}

/**************************************************************************************************/
void LsToolButtonRight::initFinalImage()
{
    qCDebug( LOG_LSTOOLBUTTONRIGHT ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 4 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsToolButtonRight::initOutlines()
{
    qCDebug( LOG_LSTOOLBUTTONRIGHT ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                0,
                                STDHEIGHT,
                                STDHEIGHT,
                                0);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     2,
                                     0,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     0);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     4,
                                     0,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     0);
}
