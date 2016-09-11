#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsSliderIndicator : public LsControls
{
    Q_OBJECT

public:
    explicit LsSliderIndicator( QObject *a_parent = nullptr );
    virtual ~LsSliderIndicator();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutline() Q_DECL_OVERRIDE;
    void initControl() Q_DECL_OVERRIDE;
};
