#pragma once
#include <QObject>


class LsControlsRenderer : public QObject
{
    Q_OBJECT

public:
    explicit LsControlsRenderer( QObject *a_parent = nullptr );
    virtual ~LsControlsRenderer();

    void renderAll();

private:
    void renderButton();
};
