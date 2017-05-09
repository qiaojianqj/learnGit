#include "DrvCmdProcPack.h"

CDrvCmdProcPack::CDrvCmdProcPack()
{
   m_pDrvMgr = NULL;
}

CDrvCmdProcPack::~CDrvCmdProcPack()
{
    if (NULL != m_pDrvMgr)
    {
        m_pDrvMgr = NULL;
    }
}

void CDrvCmdProcPack::SetDrvManager(CDrvManager *pDrvMgr)
{
    m_pDrvMgr = pDrvMgr;
}

void CDrvCmdProcPack::AddCmdFn(DWORD dwCmd, DOCMDPACKFN func)
{
    //CSS_CHECK_POINT_RET_VOID(m_pDrvMgr);
    m_pDrvMgr->AddCmdFn(dwCmd, func, this);
}
