#include "lscontrolsrenderer.h"
#include <QDebug>
#include <QLoggingCategory>
#include <QImage>
#include <QPainter>
#include <QPen>
#include <QDir>

Q_LOGGING_CATEGORY( LOG_LSCONTROLSRENDERER, "LsControlsRenderer", QtDebugMsg )

LsControlsRenderer::LsControlsRenderer( QObject *a_parent )
    : QObject( a_parent )
{
    qCDebug( LOG_LSCONTROLSRENDERER ) << "LsControlsRenderer()";
}

LsControlsRenderer::~LsControlsRenderer()
{
    qCDebug( LOG_LSCONTROLSRENDERER ) << "~LsControlsRenderer()";
}


void LsControlsRenderer::renderAll()
{
    qCDebug( LOG_LSCONTROLSRENDERER ) << "renderAll()";
    renderButton();
}

void LsControlsRenderer::renderButton()
{
    qCDebug( LOG_LSCONTROLSRENDERER ) << "renderButton()";

    // Prepare empty transparent image
    QImage image( 214+64, 64+64, QImage::Format_ARGB32 );
    image.fill( 0x00000000 );
    QPainter painter( &image );
    painter.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );

    // Hole contour
    QPainterPath path;
    path.addRoundedRect( QRectF( 32, 32, 214, 64 ), 32, 32 );

    // Darken hole
    painter.setPen( Qt::NoPen );
    painter.fillPath( path, QBrush( QColor( 0, 0, 0, 12 ) ) );

    painter.setClipPath(path);

    //painter.setClipping(false);
    {
        // Draw show in new image
        QImage image2( 214+64, 64+64, QImage::Format_ARGB32 );
        image2.fill( 0x00000000 );
        QPainter painter2( &image2 );
        painter2.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter2.setPen(QPen(QColor(0,0,0,32),5));
        painter2.drawPath(path);

        // TODO blur

        // Draw shadow in main image
        painter.drawImage(QRectF(0,0,214+64,64+64), image2, QRectF(0,-1,214+64,64+64));
    }

    {
        // Draw show in new image
        QImage image2( 214+64, 64+64, QImage::Format_ARGB32 );
        image2.fill( 0x00000000 );
        QPainter painter2( &image2 );
        painter2.setRenderHints( QPainter::Antialiasing | QPainter::HighQualityAntialiasing );
        painter2.setPen(QPen(QColor(255,255,255,32),5));
        painter2.drawPath(path);

        // TODO blur

        // Draw shadow in main image
        //painter.drawImage(QRectF(0,0,214+64,64+64), image2, QRectF(0,1,214+64,64+64));
    }

    path.setFillRule(Qt::WindingFill);
    painter.setClipPath(path);
    //painter.setClipPath(path.toReversed());
    painter.setPen(QPen(QColor(0,0,0), 25));
    painter.drawLine(0,0,100,100);
    QDir outputdir( "/home/henklaak/Projects/QmlStyleLaaksoft/src/libs/LsControlsPlugin/Images" );
    image.save( outputdir.absoluteFilePath( "button.png" ) );
}
