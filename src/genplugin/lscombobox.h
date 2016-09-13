#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsComboBox : public LsControls
{
    Q_OBJECT

public:
    explicit LsComboBox( QObject *a_parent = nullptr );
    virtual ~LsComboBox();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
