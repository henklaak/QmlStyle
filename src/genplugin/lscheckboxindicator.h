#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsCheckBox : public LsControls
{
    Q_OBJECT

public:
    explicit LsCheckBox( QObject *a_parent = nullptr );
    virtual ~LsCheckBox();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutline() Q_DECL_OVERRIDE;
    void initControl() Q_DECL_OVERRIDE;
};
