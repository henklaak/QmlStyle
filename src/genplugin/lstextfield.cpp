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

    m_imgFinalEmpty = QImage( MARGIN + 4 * STDWIDTH + MARGIN,
                              MARGIN + 2 * STDHEIGHT + MARGIN,
                              QImage::Format_ARGB32 );
}

/**************************************************************************************************/
void LsTextField::initOutlines()
{
    qCDebug( LOG_LSTEXTFIELD ) << "initOutline()";

    m_outlinePath = getOutline( MARGIN + 0,
                                MARGIN + 0,
                                4 * STDWIDTH,
                                2 * STDHEIGHT,
                                0,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4,
                                STDHEIGHT/4);
}

