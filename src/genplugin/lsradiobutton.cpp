#include "lsradiobutton.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSRADIOBUTTON, "LsRadioButton", QtDebugMsg )


/**************************************************************************************************/
LsRadioButton::LsRadioButton( QObject *a_parent )
    : LsControls( "RadioButton", a_parent )
{
    qCDebug( LOG_LSRADIOBUTTON ) << "LsRadioButton()";
}

/**************************************************************************************************/
LsRadioButton::~LsRadioButton()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "~LsRadioButton()";
}

/**************************************************************************************************/
void LsRadioButton::initFinalImage()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initFinalImage()";

    m_imgFinal = QImage( 32+64, 32+64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsRadioButton::initOutline()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 32, 32 ), 16, 16 );
}

/**************************************************************************************************/
void LsRadioButton::initControl()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initControl()";
}

