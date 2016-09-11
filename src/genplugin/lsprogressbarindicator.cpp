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

    m_imgFinalEmpty = QImage( 200 + 64, 32 + 64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsProgressBarIndicator::initOutline()
{
    qCDebug( LOG_LSPROGRESSBARINDICATOR ) << "initOutline()";

    m_outlinePath = QPainterPath();
//    m_outlinePath.addRoundedRect( QRectF( 32, 36, 200, 24 ), 8, 8 );
}

/**************************************************************************************************/
void LsProgressBarIndicator::initControl()
{
    qCDebug( LOG_LSPROGRESSBARINDICATOR ) << "initControl()";

    m_controlPathOuter = QPainterPath();
    m_controlPathOuter.addRoundedRect( QRectF( 34, 38, 196, 20 ), 6, 6 );

    m_controlPathInner = QPainterPath();
    m_controlPathInner.addRoundedRect( QRectF( 37, 41, 190, 19 ), 3, 3 );
}
