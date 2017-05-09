#ifndef _DRVMANAGER_H
#define _DRVMANAGER_H
#include <iostream>
using namespace std;

#define     DRV_CMD_MAX_NUM                     1000

class CDrvCmdProcPack;
typedef unsigned int       DWORD;
typedef DWORD 			HERROR;
struct T_DrvMessage{
	DWORD code;
};
typedef HERROR (CDrvCmdProcPack::*DOCMDPACKFN)(T_DrvMessage *,T_DrvMessage *);

class CDrvManager
{
public:
    // ���캯����
    CDrvManager();
    // ����������
    virtual ~CDrvManager();
	HERROR OnSet(const DWORD dwCmdCode,              // ������롣
			T_DrvMessage *ptInMsg = NULL,   // ������Ϣ�� 
			T_DrvMessage *ptOutMsg = NULL); 
	void AddCmdFn(DWORD dwCmd, DOCMDPACKFN func, CDrvCmdProcPack *pcmdPack);
private:
    struct TCmdPackCollect
    {
      CDrvCmdProcPack *m_pCmdPack;
      DOCMDPACKFN      m_function;
    };	
	TCmdPackCollect m_arrCmdFn[DRV_CMD_MAX_NUM];
};
#endif