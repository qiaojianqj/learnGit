#include "DrvFtmCmdProcPack.h"

CDrvFtmCmdProcPack::CDrvFtmCmdProcPack()
{
}

CDrvFtmCmdProcPack::~CDrvFtmCmdProcPack()
{
}

void CDrvFtmCmdProcPack::RegisterCmd()
{
    AddCmdFn(1, (DOCMDPACKFN)&CDrvFtmCmdProcPack::DoSetFunc1);
    AddCmdFn(2, (DOCMDPACKFN)&CDrvFtmCmdProcPack::DoSetFunc2);
}

void CDrvFtmCmdProcPack::SetDrvManager( CDrvManager *pDrvMgr )
{
    CDrvCmdProcPack::SetDrvManager(pDrvMgr);
}

HERROR CDrvFtmCmdProcPack::DoSetFunc1( T_DrvMessage *ptInMsg, T_DrvMessage *ptOutMsg )
{
	printf("DoSetFunc1\n");
	printf("T_Drvmessage.code: %d\n", ptInMsg->code);
	return 0;
}
HERROR CDrvFtmCmdProcPack::DoSetFunc2( T_DrvMessage *ptInMsg, T_DrvMessage *ptOutMsg )
{
	printf("DoSetFunc2\n");
	printf("T_Drvmessage.code: %d\n", ptInMsg->code);
	return 0;
}
