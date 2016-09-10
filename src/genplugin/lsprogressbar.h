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

    void initImages() Q_DECL_OVERRIDE;
    void initOutline() Q_DECL_OVERRIDE;
};
