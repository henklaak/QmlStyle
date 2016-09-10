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
void LsRadioButton::initImages()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initImages()";

    m_imgResult = QImage( 32+64, 32+64, QImage::Format_ARGB32 );
    m_imgResult.fill( 0x00000000 );

    m_imgOutline       = m_imgResult;
    m_imgEdgehighlight = m_imgResult;
    m_imgEdgeshadow    = m_imgResult;
    m_imgOcclusion     = m_imgResult;
}

/**************************************************************************************************/
void LsRadioButton::initOutline()
{
    qCDebug( LOG_LSRADIOBUTTON ) << "initOutline()";

    m_contour = QPainterPath();
    m_contour.addRoundedRect( QRectF( 32, 32, 32, 32 ), 16, 16 );
}

