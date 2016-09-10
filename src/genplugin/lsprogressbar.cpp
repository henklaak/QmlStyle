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

    m_imgFinalEmpty = QImage( 200 + 64, 24 + 64, QImage::Format_ARGB32 );
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

    m_controlPath = QPainterPath();
    m_controlPath.addRoundedRect( QRectF( 34, 34, 196, 20 ), 6, 6 );

    m_controlPath2 = QPainterPath();
    m_controlPath2.addRoundedRect( QRectF( 37, 37, 190, 19 ), 3, 3 );
}
