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

    m_imgFinalEmpty = QImage( MARGIN + 8 * STDWIDTH + MARGIN,
                              MARGIN + 3 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsComboBox::initOutlines()
{
    qCDebug( LOG_LSCOMBOBOX ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                8 * STDWIDTH,
                                3 * STDHEIGHT,
                                0,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4);

    m_controlPathOuter = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     2,
                                     STDHEIGHT/4,
                                     STDHEIGHT/4,
                                     STDHEIGHT/4,
                                     STDHEIGHT/4);

    m_controlPathInner = getOutline( MARGIN + 0,
                                     MARGIN + 0,
                                     8 * STDWIDTH,
                                     3 * STDHEIGHT,
                                     4,
                                     STDHEIGHT/4,
                                     STDHEIGHT/4,
                                     STDHEIGHT/4,
                                     STDHEIGHT/4);
}

