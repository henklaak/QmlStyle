#include "lstextfield.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSTEXTFIELD, "LsTextField", QtWarningMsg )


/**************************************************************************************************/
LsTextField::LsTextField( QObject *a_parent )
    : LsControls( "TextField", a_parent )
{
    qCDebug( LOG_LSTEXTFIELD ) << "LsTextField()";
}

/**************************************************************************************************/
LsTextField::~LsTextField()
{
    qCDebug( LOG_LSTEXTFIELD ) << "~LsTextField()";
}

/**************************************************************************************************/
void LsTextField::initFinalImage()
{
    qCDebug( LOG_LSTEXTFIELD ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( 214 + 64, 48 + 64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsTextField::initOutline()
{
    qCDebug( LOG_LSTEXTFIELD ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 214, 48 ), 8, 8 );
}

/**************************************************************************************************/
void LsTextField::initControl()
{
    qCDebug( LOG_LSTEXTFIELD ) << "initControl()";
}

