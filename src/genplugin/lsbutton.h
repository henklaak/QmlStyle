#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsButton : public LsControls
{
    Q_OBJECT

public:
    explicit LsButton( QObject *a_parent = nullptr );
    virtual ~LsButton();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
