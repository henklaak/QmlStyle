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
void LsButton::initImages()
{
    qCDebug( LOG_LSBUTTON ) << "initImages()";

    m_imgResult = QImage( 214+64, 64+64, QImage::Format_ARGB32 );
    m_imgResult.fill( 0x00000000 );

    m_imgOutline       = m_imgResult;
    m_imgEdgehighlight = m_imgResult;
    m_imgEdgeshadow    = m_imgResult;
    m_imgOcclusion     = m_imgResult;
}

/**************************************************************************************************/
void LsButton::initOutline()
{
    qCDebug( LOG_LSBUTTON ) << "initOutline()";

    m_contour = QPainterPath();
    m_contour.addRoundedRect( QRectF( 32, 32, 214, 64 ), 32, 32 );
}

