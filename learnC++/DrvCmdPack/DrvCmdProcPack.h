#include "DrvManager.h"

class CDrvCmdProcPack  
{
public:
	CDrvCmdProcPack();
	virtual ~CDrvCmdProcPack();

    virtual void SetDrvManager(CDrvManager *pDrvMgr);
	
    virtual void RegisterCmd() = 0;
protected:
    /// �������б�����������
	void AddCmdFn(DWORD dwCmd,DOCMDPACKFN func);
protected:
    CDrvManager *m_pDrvMgr;
};
