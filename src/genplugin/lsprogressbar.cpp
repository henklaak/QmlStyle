#include "lsprogressbar.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSPROGRESSBAR, "LsProgressBar", QtWarningMsg )


/**************************************************************************************************/
LsProgressBar::LsProgressBar( QObject *a_parent )
    : LsControls( "ProgressBar", a_parent )
{
    qCDebug( LOG_LSPROGRESSBAR ) << "LsRadioButton()";
}

/**************************************************************************************************/
LsProgressBar::~LsProgressBar()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "~LsRadioButton()";
}

/**************************************************************************************************/
void LsProgressBar::initFinalImage()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 8 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsProgressBar::initOutlines()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                8 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4 );
}
