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
    void initOutlines() Q_DECL_OVERRIDE;
};
