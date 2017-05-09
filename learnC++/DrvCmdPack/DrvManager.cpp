#include "DrvManager.h"

CDrvManager::CDrvManager()
{
	memset(m_arrCmdFn, 0, sizeof(m_arrCmdFn));
}

CDrvManager::~CDrvManager()
{
}

void CDrvManager::AddCmdFn(DWORD dwCmd, DOCMDPACKFN func, CDrvCmdProcPack *pcmdPack)
{
	//CSS_CHECK_CONDITION_RET_VOID(dwCmd >= DRV_CMD_MAX_NUM);
	m_arrCmdFn[dwCmd].m_function = func;
	m_arrCmdFn[dwCmd].m_pCmdPack = pcmdPack;
}

HERROR CDrvManager::OnSet(const DWORD dwCmdCode, 
                          T_DrvMessage *ptInMsg, 
                          T_DrvMessage *ptOutMsg)
{
	HERROR  errCode     = 0;
	TCmdPackCollect &tCmdFn = m_arrCmdFn[dwCmdCode];
	errCode = ((tCmdFn.m_pCmdPack)->*(tCmdFn.m_function))(ptInMsg,ptOutMsg);
	return errCode;
}