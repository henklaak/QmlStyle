#include "lscheckbox.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSCHECKBOX, "LsCheckBox", QtDebugMsg )


/**************************************************************************************************/
LsCheckBox::LsCheckBox( QObject *a_parent )
    : LsControls( "CheckBox", a_parent )
{
    qCDebug( LOG_LSCHECKBOX ) << "LsCheckBox()";
}

/**************************************************************************************************/
LsCheckBox::~LsCheckBox()
{
    qCDebug( LOG_LSCHECKBOX ) << "~LsCheckBox()";
}

/**************************************************************************************************/
void LsCheckBox::initImages()
{
    qCDebug( LOG_LSCHECKBOX ) << "initImages()";

    m_imgResult = QImage( 32+64, 32+64, QImage::Format_ARGB32 );
    m_imgResult.fill( 0x00000000 );

    m_imgOutline       = m_imgResult;
    m_imgEdgehighlight = m_imgResult;
    m_imgEdgeshadow    = m_imgResult;
    m_imgOcclusion     = m_imgResult;
}

/**************************************************************************************************/
void LsCheckBox::initOutline()
{
    qCDebug( LOG_LSCHECKBOX ) << "initOutline()";

    m_contour = QPainterPath();
    m_contour.addRoundedRect( QRectF( 32, 32, 32, 32 ), 8, 8 );
}

