#include "DrvManager.h"

class CCssDrvApiCreator
{
public:
    CCssDrvApiCreator();
    virtual ~CCssDrvApiCreator();
    void SetDrvMgr(CDrvManager *pDrvMgr) { m_pDrvMgr = pDrvMgr; }
    CDrvManager &GetDrvMgr();
	HERROR SendDrvApi(const DWORD dwCmdCode, T_DrvMessage tInMsg);
private:	
	CDrvManager *m_pDrvMgr;
};