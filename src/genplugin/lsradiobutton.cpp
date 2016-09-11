#include "lsradiobutton.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSRADIOBUTTON, "LsRadioButton", QtWarningMsg )


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

    m_imgFinalEmpty = QImage( 32 + 64, 32 + 64, QImage::Format_ARGB32 );
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

    m_controlPathOuter = QPainterPath();
    m_controlPathOuter.addRoundedRect( QRectF( 34, 34, 28, 28 ), 14, 14 );

    m_controlPathInner = QPainterPath();
    m_controlPathInner.addRoundedRect( QRectF( 37, 37, 22, 22 ), 11, 11 );
}
