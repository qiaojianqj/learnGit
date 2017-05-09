#include "CCssDrvApiCreator.h"

CCssDrvApiCreator::CCssDrvApiCreator()
:m_pDrvMgr(NULL)
{
}

CCssDrvApiCreator::~CCssDrvApiCreator()
{
    m_pDrvMgr = NULL;
}

CDrvManager & CCssDrvApiCreator::GetDrvMgr()
{
	return (*m_pDrvMgr); 
}

HERROR CCssDrvApiCreator::SendDrvApi(const DWORD dwCmdCode, T_DrvMessage tInMsg)
{
	GetDrvMgr().OnSet(dwCmdCode, &tInMsg, NULL);
	return 0;
}