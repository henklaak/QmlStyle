#include "lsbutton.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSBUTTON, "LsButton", QtWarningMsg )


/**************************************************************************************************/
LsButton::LsButton( QObject *a_parent )
    : LsControls( "Button", a_parent )
{
    qCDebug( LOG_LSBUTTON ) << "LsButton()";
}

/**************************************************************************************************/
LsButton::~LsButton()
{
    qCDebug( LOG_LSBUTTON ) << "~LsButton()";
}

/**************************************************************************************************/
void LsButton::initFinalImage()
{
    qCDebug( LOG_LSBUTTON ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 8 * STDWIDTH + MARGIN,
                              MARGIN + 3 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsButton::initOutlines()
{
    qCDebug( LOG_LSBUTTON ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                8 * STDWIDTH,
                                3 * STDHEIGHT,
                                0,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     2,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     4,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT,
                                     STDHEIGHT);
}
