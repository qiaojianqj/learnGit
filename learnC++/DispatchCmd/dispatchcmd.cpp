#include <stdio.h>

class CCssCmd;
typedef unsigned int UINT;
typedef unsigned int HERROR;
typedef char BYTE;
typedef HERROR (CCssCmd::*PFN_CMD) (void);
typedef PFN_CMD MSG_FUN;

typedef struct CSS_CMDMSG_ENTRY{
	UINT nMsgID;
	MSG_FUN mf;
}CSS_CMDMSG_ENTRY;

typedef struct T_CmdInf{
	BYTE ucOperType;
	BYTE *pRecvCmd;
}T_CmdInf;

typedef HERROR (CCssCmd::*PFN_CMDINF) (const T_CmdInf&);

class CCssCmd{};

class CCmdProcBase: public CCssCmd
{
public:
	HERROR DispatchCommand(const T_CmdInf &tCmd)
	{
		HERROR hRet = 0;
		CSS_CMDMSG_ENTRY *ptEntry = &msgEntries[1];
		hRet = (this->*(PFN_CMDINF)ptEntry->mf) (tCmd);
		return hRet;
	}

	HERROR OnMyFunc(const T_CmdInf &tCmdInf)
	{
		printf("On My Func!\n");
		printf("tCmdInf.ucOperType: %d, tCmdInf.pRecvCmd: %s\n", tCmdInf.ucOperType, tCmdInf.pRecvCmd);
		return 0;
	}

	static CSS_CMDMSG_ENTRY msgEntries[];
};

CSS_CMDMSG_ENTRY CCmdProcBase::msgEntries[] = {
	{0, (PFN_CMD)0},
	{1, (PFN_CMD)(HERROR (CCssCmd::*) (const T_CmdInf &)) &CCmdProcBase::OnMyFunc}
};

int main(int argc, const char *argv[])
{
	T_CmdInf mycmdinf = {3,(BYTE*)"You Are Sun Of Beatch!"};
	CCmdProcBase mycmdproc;
	mycmdproc.DispatchCommand(mycmdinf);
	return 0;
}


