#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsToolButtonBoth : public LsControls
{
    Q_OBJECT

public:
    explicit LsToolButtonBoth( QObject *a_parent = nullptr );
    virtual ~LsToolButtonBoth();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
