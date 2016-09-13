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

    m_imgFinalEmpty = QImage( 214 + 64, 48 + 64, QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsComboBox::initOutlines()
{
    qCDebug( LOG_LSCOMBOBOX ) << "initOutline()";

    m_outlinePath = QPainterPath();
    m_outlinePath.addRoundedRect( QRectF( 32, 32, 214, 48 ), 8, 8 );

    m_controlPathOuter = QPainterPath();
    m_controlPathOuter.addRoundedRect( QRectF( 34, 34, 210, 44 ), 6, 6 );

    m_controlPathInner = QPainterPath();
    m_controlPathInner.addRoundedRect( QRectF( 37, 37, 204, 38 ), 3, 3 );

}

