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

    m_imgFinalEmpty = QImage( MARGIN + 2 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsRadioButton::initOutlines()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                2 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                2 * STDWIDTH,
                                2 * STDHEIGHT,
                                2,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT);

    m_controlPathInner = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                2 * STDWIDTH,
                                2 * STDHEIGHT,
                                4,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT,
                                STDHEIGHT);
}
