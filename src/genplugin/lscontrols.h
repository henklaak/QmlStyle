#pragma once
#include <QObject>
#include <QPainterPath>
#include <QImage>

/**************************************************************************************************/
class LsControls : public QObject
{
    Q_OBJECT

public:
    explicit LsControls( const QString &a_name,
                                 QObject *a_parent = nullptr );
    virtual ~LsControls();

    virtual void render() final;
    virtual void initImages() = 0;
    virtual void initOutline() = 0;
    virtual void renderOutline() final;
    virtual void renderEdgeHighlight() final;
    virtual void renderEdgeShadow() final;
    virtual void renderOcclusion() final;
    virtual void flattenImage();
    virtual void saveResult();


protected:
    QImage calcVertDerivative(const QImage &a_image, bool dir, const QColor &a_col );
    QImage calcOmniDerivative(const QImage &a_image, const QColor &a_col );
    QImage blurImage(const QImage &a_image, double radius);
    QPainterPath m_contour;
    QString m_name;

    QImage m_imgOutline;
    QImage m_imgEdgehighlight;
    QImage m_imgEdgeshadow;
    QImage m_imgOcclusion;
    QImage m_imgResult;
};
