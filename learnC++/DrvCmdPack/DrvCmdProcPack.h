#include "DrvManager.h"

class CDrvCmdProcPack  
{
public:
	CDrvCmdProcPack();
	virtual ~CDrvCmdProcPack();

    virtual void SetDrvManager(CDrvManager *pDrvMgr);
	
    virtual void RegisterCmd() = 0;
protected:
    /// 向命令列表中增加命令
	void AddCmdFn(DWORD dwCmd,DOCMDPACKFN func);
protected:
    CDrvManager *m_pDrvMgr;
};
