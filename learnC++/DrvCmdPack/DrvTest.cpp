#include "CCssDrvApiCreator.h"
#include "DrvFtmCmdProcPack.h"

int main()
{
	CDrvManager drvmanager;
	CDrvFtmCmdProcPack drvftmcmdprocpack;
	drvftmcmdprocpack.SetDrvManager(&drvmanager);
	drvftmcmdprocpack.RegisterCmd();
	CCssDrvApiCreator drvapicreator;
	drvapicreator.SetDrvMgr(&drvmanager);
	T_DrvMessage tInMsg1 = {1};
	T_DrvMessage tInMsg2 = {2};
	drvapicreator.SendDrvApi(1, tInMsg1);
	drvapicreator.SendDrvApi(2, tInMsg2);
	//getchar();
	return 0;
}
