#include "lsradiobutton.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSRADIOBUTTON, "LsRadioButton", QtWarningMsg )


/**************************************************************************************************/
LsRadioButton::LsRadioButton( QObject *a_parent )
    : LsControls( "RadioButton", a_parent )
{
    qCDebug( LOG_LSRADIOBUTTON ) << "LsRadioButton()";
}

/**************************************************************************************************/
LsRadioButton::~LsRadioButton()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "~LsRadioButton()";
}

/**************************************************************************************************/
void LsRadioButton::initFinalImage()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 1 * STDWIDTH + MARGIN,
                              MARGIN + 1 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsRadioButton::initOutlines()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                1 * STDWIDTH,
                                1 * STDHEIGHT,
                                0,
                                STDHEIGHT/2,
                                STDHEIGHT/2,
                                STDHEIGHT/2,
                                STDHEIGHT/2);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                1 * STDWIDTH,
                                1 * STDHEIGHT,
                                2,
                                STDHEIGHT/2,
                                STDHEIGHT/2,
                                STDHEIGHT/2,
                                STDHEIGHT/2);

    m_controlPathInner = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                1 * STDWIDTH,
                                1 * STDHEIGHT,
                                4,
                                STDHEIGHT/2,
                                STDHEIGHT/2,
                                STDHEIGHT/2,
                                STDHEIGHT/2);
}
