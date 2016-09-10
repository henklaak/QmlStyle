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
void LsCheckBox::initFinalImage()
{
    qCDebug( LOG_LSCHECKBOX ) << "initFinalImage()";

    m_imgFinal = QImage( 32+64, 32+64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsCheckBox::initOutline()
{
    qCDebug( LOG_LSCHECKBOX ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 32, 32 ), 8, 8 );
}

/**************************************************************************************************/
void LsCheckBox::initControl()
{
    qCDebug( LOG_LSCHECKBOX ) << "initControl()";
}


