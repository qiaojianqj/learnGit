#include <iostream>
#include <map>
using namespace std;

typedef unsigned int UINT;
typedef unsigned int WORD;
typedef unsigned int HERROR;
typedef char BYTE;

class CCssCmd;
typedef HERROR (CCssCmd::*MSG_FUN) (void);

typedef struct T_CmdInf{
	BYTE ucOperType;
	BYTE *pRecvCmd;
}T_CmdInf;

typedef struct CSS_CMDMSG_ENTRY{
	UINT nMsgID;
	MSG_FUN mf;
}T_CssCmdMsgEntry;

typedef map<WORD, CSS_CMDMSG_ENTRY*> CSS_MAP_CMDENTRY;

class CSS_MSGMAP{
	public:
		const CSS_MSGMAP *pBaseMsgMap;
		CSS_CMDMSG_ENTRY *lpEntries;
		CSS_MAP_CMDENTRY mapCmdEntry;
		const UINT *pival;
		CSS_MSGMAP(const CSS_MSGMAP *pMsgMap, CSS_CMDMSG_ENTRY *msgEntries):
		pBaseMsgMap(pMsgMap),
		lpEntries(msgEntries),
		pival(0)
		{
			//pBaseMsgMap = pMsgMap;
			//lpEntries = msgEntries;
			//pival = 0;
		}
		void InitMapCmdEntry()
		{
			for(int i = 0; lpEntries[i].nMsgID != 0; i++)	
			{
				mapCmdEntry.insert(make_pair(lpEntries[i].nMsgID, &lpEntries[i]));
			}
		}
};

class CCssCmd{
	public:
		virtual CSS_MSGMAP* GetMessageMap();
	protected:
		static void InitMapMsgEntry();
		static CSS_CMDMSG_ENTRY msgEntries[];
		static CSS_MSGMAP msgMap;
};

CSS_MSGMAP* CCssCmd::GetMessageMap()
{
	return &CCssCmd::msgMap;
}

void CCssCmd::InitMapMsgEntry()
{
	CCssCmd::msgMap.InitMapCmdEntry();
}

CSS_MSGMAP CCssCmd::msgMap(NULL, CCssCmd::msgEntries);
CSS_CMDMSG_ENTRY CCssCmd::msgEntries[] = {
	{0, (MSG_FUN)0}
};

class CQosCmdProc: public CCssCmd
{
	public:
		virtual CSS_MSGMAP* GetMessageMap();
	protected:
		static void InitMapMsgEntry();
		static CSS_CMDMSG_ENTRY msgEntries[];
		static CSS_MSGMAP msgMap;
	public:
		HERROR OnAclCmd(const T_CmdInf &tCmdInf);
};

CSS_MSGMAP* CQosCmdProc::GetMessageMap()
{
	return &CQosCmdProc::msgMap;
}

void CQosCmdProc::InitMapMsgEntry()
{
	CQosCmdProc::msgMap.InitMapCmdEntry();
}

CSS_MSGMAP CQosCmdProc::msgMap(NULL, CQosCmdProc::msgEntries);
CSS_CMDMSG_ENTRY CQosCmdProc::msgEntries[] = {
	{0, (MSG_FUN)0},
	{1, (MSG_FUN)(HERROR (CCssCmd::*) (const T_CmdInf &))&CQosCmdProc::OnAclCmd},
};

HERROR CQosCmdProc::OnAclCmd(const T_CmdInf &tCmdInf)
{
	printf("tCmdInf.ucOperType: %d, tCmdInf.pRecvCmd: %s\n", tCmdInf.ucOperType, tCmdInf.pRecvCmd);
	return 0;
}

int main()
{
	T_CmdInf cmdinfo = {1, (BYTE*)"Welcome Bitches!"};
	CQosCmdProc qoscmd;
	qoscmd.OnAclCmd(cmdinfo);
	return 0;
}
