#include "lstoolbutton.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSTOOLBUTTON, "LsToolButton", QtWarningMsg )


/**************************************************************************************************/
LsToolButton::LsToolButton( QObject *a_parent )
    : LsControls( "ToolButton", a_parent )
{
    qCDebug( LOG_LSTOOLBUTTON ) << "LsToolButton()";
}

/**************************************************************************************************/
LsToolButton::~LsToolButton()
{
    qCDebug( LOG_LSTOOLBUTTON ) << "~LsToolButton()";
}

/**************************************************************************************************/
void LsToolButton::initFinalImage()
{
    qCDebug( LOG_LSTOOLBUTTON ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 4 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsToolButton::initOutlines()
{
    qCDebug( LOG_LSTOOLBUTTON ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                0,
                                0,
                                0,
                                0);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     2,
                                     0,
                                     0,
                                     0,
                                     0);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     4 * STDWIDTH,
                                     2 * STDHEIGHT,
                                     4,
                                     0,
                                     0,
                                     0,
                                     0);}
