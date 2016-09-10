#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsRadioButton : public LsControls
{
    Q_OBJECT

public:
    explicit LsRadioButton( QObject *a_parent = nullptr );
    virtual ~LsRadioButton();

    void initImages() Q_DECL_OVERRIDE;
    void initOutline() Q_DECL_OVERRIDE;
};
