#include "lsprogressbarindicator.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSPROGRESSBARINDICATOR, "LsProgressBarIndicator", QtWarningMsg )


/**************************************************************************************************/
LsProgressBarIndicator::LsProgressBarIndicator( QObject *a_parent )
    : LsControls( "ProgressBarIndicator", a_parent )
{
    qCDebug( LOG_LSPROGRESSBARINDICATOR ) << "LsProgressBarIndicator()";
}

/**************************************************************************************************/
LsProgressBarIndicator::~LsProgressBarIndicator()
{
    qCDebug( LOG_LSPROGRESSBARINDICATOR ) << "~LsProgressBarIndicator()";
}

/**************************************************************************************************/
void LsProgressBarIndicator::initFinalImage()
{
    qCDebug( LOG_LSPROGRESSBARINDICATOR ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( MARGIN + 4 * STDWIDTH + MARGIN,
                              MARGIN + 1 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsProgressBarIndicator::initOutlines()
{
    qCDebug( LOG_LSPROGRESSBARINDICATOR ) << "initOutline()";

    m_controlPathOuter = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                1 * STDHEIGHT,
                                2,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4 );
    m_controlPathInner = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                1 * STDHEIGHT,
                                4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4,
                                STDHEIGHT / 4 );
}
