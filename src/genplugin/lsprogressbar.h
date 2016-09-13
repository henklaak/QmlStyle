#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsProgressBar : public LsControls
{
    Q_OBJECT

public:
    explicit LsProgressBar( QObject *a_parent = nullptr );
    virtual ~LsProgressBar();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
