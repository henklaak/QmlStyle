#include "lscombobox.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QPainter>

Q_LOGGING_CATEGORY( LOG_LSCOMBOBOX, "LsComboBox", QtWarningMsg )


/**************************************************************************************************/
LsComboBox::LsComboBox( QObject *a_parent )
    : LsControls( "ComboBox", a_parent )
{
    qCDebug( LOG_LSCOMBOBOX ) << "LsComboBox()";
}

/**************************************************************************************************/
LsComboBox::~LsComboBox()
{
    qCDebug( LOG_LSCOMBOBOX ) << "~LsComboBox()";
}

/**************************************************************************************************/
void LsComboBox::initFinalImage()
{
    qCDebug( LOG_LSCOMBOBOX ) << "initFinalImage()";

    m_imgFinalEmpty = QImage( 214 + 64, 64 + 64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsComboBox::initOutline()
{
    qCDebug( LOG_LSCOMBOBOX ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 214, 64 ), 8, 8 );
}

/**************************************************************************************************/
void LsComboBox::initControl()
{
    qCDebug( LOG_LSCOMBOBOX ) << "initControl()";
}

