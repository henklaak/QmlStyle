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
void LsProgressBar::initImages()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "initImages()";

    m_imgResult = QImage( 200+64, 24+64, QImage::Format_ARGB32 );
    m_imgResult.fill( 0x00000000 );

    m_imgOutline       = m_imgResult;
    m_imgEdgehighlight = m_imgResult;
    m_imgEdgeshadow    = m_imgResult;
    m_imgOcclusion     = m_imgResult;
}

/**************************************************************************************************/
void LsProgressBar::initOutline()
{
    qCDebug( LOG_LSPROGRESSBAR ) << "initOutline()";

    m_contour = QPainterPath();
    m_contour.addRoundedRect( QRectF( 32, 32, 200, 24 ), 8, 8 );
}

