#pragma once
#include <QObject>

#include <lscontrols.h>

/**************************************************************************************************/
class LsToolButtonRight : public LsControls
{
    Q_OBJECT

public:
    explicit LsToolButtonRight( QObject *a_parent = nullptr );
    virtual ~LsToolButtonRight();

    void initFinalImage() Q_DECL_OVERRIDE;
    void initOutlines() Q_DECL_OVERRIDE;
};
