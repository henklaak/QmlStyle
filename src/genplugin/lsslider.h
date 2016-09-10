#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsSlider : public LsControls
{
    Q_OBJECT

public:
    explicit LsSlider( QObject *a_parent = nullptr );
    virtual ~LsSlider();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutline() Q_DECL_OVERRIDE;
    void initControl() Q_DECL_OVERRIDE;
};
