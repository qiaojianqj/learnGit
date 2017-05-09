#include "DrvCmdProcpack.h"

class CDrvFtmCmdProcPack : public CDrvCmdProcPack  
{
public:
    CDrvFtmCmdProcPack();
    virtual ~CDrvFtmCmdProcPack();
	virtual void RegisterCmd();
	virtual void SetDrvManager(CDrvManager *pDrvMgr);
protected:
	virtual HERROR DoSetFunc1( T_DrvMessage *ptInMsg, T_DrvMessage *ptOutMsg );
    virtual HERROR DoSetFunc2( T_DrvMessage *ptInMsg, T_DrvMessage *ptOutMsg );
};