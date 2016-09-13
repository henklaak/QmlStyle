#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsProgressBarIndicator : public LsControls
{
    Q_OBJECT

public:
    explicit LsProgressBarIndicator( QObject *a_parent = nullptr );
    virtual ~LsProgressBarIndicator();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
