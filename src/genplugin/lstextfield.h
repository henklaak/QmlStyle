#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsTextField : public LsControls
{
    Q_OBJECT

public:
    explicit LsTextField( QObject *a_parent = nullptr );
    virtual ~LsTextField();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutline() Q_DECL_OVERRIDE;
    void initControl() Q_DECL_OVERRIDE;
};
