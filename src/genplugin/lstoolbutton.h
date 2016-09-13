#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsToolButton : public LsControls
{
    Q_OBJECT

public:
    explicit LsToolButton( QObject *a_parent = nullptr );
    virtual ~LsToolButton();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
