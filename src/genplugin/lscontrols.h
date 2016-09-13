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
    virtual void initOutlines() = 0;
    virtual void initImages() final;

    virtual void renderOutlineComponents() final;
    virtual void renderControlEnabledComponents() final;
    virtual void renderControlPressedComponents() final;
    virtual void renderControlCheckedComponents() final;

    virtual void flattenImage();
    virtual void saveResult();

protected:
    QPainterPath getOutline(int a_x,
                            int a_y,
                            int a_width,
                            int a_height,
                            int a_shrink,
                            int a_radius1,
                            int a_radius2,
                            int a_radius3,
                            int a_radius4);

    QString m_name;

    QImage m_imgFinalEmpty;

    QPainterPath m_outlinePath;
    QPainterPath m_controlPathOuter;
    QPainterPath m_controlPathInner;
    QPainterPath m_controlPathChecked;

    static const int MARGIN;
    static const int STDWIDTH;
    static const int STDHEIGHT;

private:
    QImage calcVertDerivative( const QImage &a_image, bool dir, const QColor &a_col );
    QImage calcOmniDerivative( const QImage &a_image, const QColor &a_col );
    QImage blurImage( const QImage &a_image, double radius );


    QImage m_imgOutline;
    QImage m_imgOutlineHighlight;
    QImage m_imgOutlineShadow;
    QImage m_imgOutlineOcclusion;

    QImage m_imgControlNormal;
    QImage m_imgControlNormalHighlight;
    QImage m_imgControlNormalShadow;

    QImage m_imgControlPressed;
    QImage m_imgControlPressedHighlight;
    QImage m_imgControlPressedShadow;

    QImage m_imgControlChecked;

    QImage m_imgFinalEnabledPressedChecked;
    QImage m_imgFinalEnabledPressedUnchecked;
    QImage m_imgFinalEnabledUnpressedChecked;
    QImage m_imgFinalEnabledUnpressedUnchecked;
    QImage m_imgFinalDisabledPressedChecked;
    QImage m_imgFinalDisabledPressedUnchecked;
    QImage m_imgFinalDisabledUnpressedChecked;
    QImage m_imgFinalDisabledUnpressedUnchecked;
};
