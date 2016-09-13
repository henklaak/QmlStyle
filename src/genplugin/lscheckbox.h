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
    void initOutlines() Q_DECL_OVERRIDE;
};
