#include "lscheckbox.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSCHECKBOX, "LsCheckBox", QtWarningMsg )


/**************************************************************************************************/
LsCheckBox::LsCheckBox( QObject *a_parent )
    : LsControls( "CheckBox", a_parent )
{
    qCDebug( LOG_LSCHECKBOX ) << "LsCheckBox()";
}

/**************************************************************************************************/
LsCheckBox::~LsCheckBox()
{
    qCDebug( LOG_LSCHECKBOX ) << "~LsCheckBox()";
}

/**************************************************************************************************/
void LsCheckBox::initFinalImage()
{
    qCDebug( LOG_LSCHECKBOX ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 1 * STDWIDTH + MARGIN,
                              MARGIN + 1 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsCheckBox::initOutlines()
{
    qCDebug( LOG_LSCHECKBOX ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                1 * STDWIDTH,
                                1 * STDHEIGHT,
                                0,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                1 * STDWIDTH,
                                1 * STDHEIGHT,
                                2,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4);

    m_controlPathInner = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                1 * STDWIDTH,
                                1 * STDHEIGHT,
                                4,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4);
}

