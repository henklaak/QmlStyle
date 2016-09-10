#include "lsbutton.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSBUTTON, "LsButton", QtDebugMsg )


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

    m_imgFinal = QImage( 214+64, 64+64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsButton::initOutline()
{
    qCDebug( LOG_LSBUTTON ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 214, 64 ), 32, 32 );
}

/**************************************************************************************************/
void LsButton::initControl()
{
    qCDebug( LOG_LSBUTTON ) << "initControl()";
    m_controlPath = QPainterPath();
    m_controlPath.addRoundedRect( QRectF( 34, 34, 210, 60 ), 30, 30 );

    m_controlPath2 = QPainterPath();
    m_controlPath2.addRoundedRect( QRectF( 37, 37, 204, 56 ), 27, 27 );
}


