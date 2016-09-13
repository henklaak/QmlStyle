#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsToolButtonLeft : public LsControls
{
    Q_OBJECT

public:
    explicit LsToolButtonLeft( QObject *a_parent = nullptr );
    virtual ~LsToolButtonLeft();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
