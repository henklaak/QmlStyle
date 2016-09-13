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
    void initOutlines() Q_DECL_OVERRIDE;
};
