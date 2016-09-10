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
    virtual void initFinalImage() = 0;
    virtual void initOutline() = 0;
    virtual void initControl() = 0;
    virtual void initImages() final;

    virtual void renderOutline() final;
    virtual void renderOutlineHighlight() final;
    virtual void renderOutlineShadow() final;
    virtual void renderOutlineOcclusion() final;

    virtual void renderControl() final;

    virtual void flattenImage();
    virtual void saveResult();


protected:
    QImage calcVertDerivative(const QImage &a_image, bool dir, const QColor &a_col );
    QImage calcOmniDerivative(const QImage &a_image, const QColor &a_col );
    QImage blurImage(const QImage &a_image, double radius);

    QString m_name;

    QPainterPath m_outlinePath;
    QPainterPath m_controlPath;

    QImage m_imgOutline;
    QImage m_imgOutlineHighlight;
    QImage m_imgOutlineShadow;
    QImage m_imgOutlineOcclusion;

    QImage m_imgControl;

    QImage m_imgFinal;
};
