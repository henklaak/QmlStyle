#include "lsprogressbar.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSPROGRESSBAR, "LsProgressBar", QtDebugMsg )


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

    m_imgFinal = QImage( 200+64, 24+64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsProgressBar::initOutline()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 200, 24 ), 8, 8 );
}

/**************************************************************************************************/
void LsProgressBar::initControl()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "initControl()";
}

