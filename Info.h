#pragma once
#include "stdafx.h"
#include <string>

#define SOFTWARE_VERSION "1.0.0.3"
#define SoftwareVerID "1475807714694008832"
#define PT_UPDATE_SELF	"updateselflib.exe"
#define PT_SERVICE "ManageTool.exe"
#define SYS_UPDATE 1

#define UWM_LOADING WM_USER + 8208
#define ENNABLEDLG WM_USER + 8248

using namespace std;

enum eUKStatus
{
	Load = 0,
    unLoad
};

struct deviceListItem
{
	SStringT ordernumber;
	SStringT businessname;
	SStringT itin;
	SStringT devicetypes;
	SStringT extensionnumber;
	SStringT machineID;
	SStringT deviceportnumber;
	SStringT cabinetnumber;
	SStringT	operate;
};

struct UkeyInfo
{
	wstring strReturncode; //���ش���
	wstring strReturnmsg; //������Ϣ
	wstring strSksbbh; //˰���豸���
	wstring strNsrsbh; //��˰��ʶ���
	wstring strNsrmc; //��˰������
	wstring strSwjgdm; //˰����ش���
	wstring strSwjgmc; //˰���������
	wstring strFplxdm; //��Ʊ���ʹ���
	wstring strDqsz; //��ǰʱ��
	wstring strDjsj; //�Ǽ�ʱ��
	wstring strBbh; //�汾��
	wstring strKpjh; //��Ʊ����
	wstring strQylx; //��ҵ����
	wstring strDjxh; //�Ǽ����
	wstring strKpbz; //��Ʊ��־
	wstring strTdqy; //�ض���ҵ
	wstring strNcpqy; //ũ��Ʒ��ҵ
	wstring strDxqy; //������ҵ
	wstring strXgmkjzpbs; //С��ģ����רƱ��ʶ
	wstring strEsjdcbz; //���ֻ�������־	
	wstring strCpybs; //��Ʒ�ͱ�ʶ
	wstring strCpybsyxq; //��Ʒ�ͱ�ʶ��Ч��
	wstring strCpybmdbs; //��Ʒ�Ͱ�������ʶ
	wstring strCpybmdbsyxq; //��Ʒ�Ͱ�������Ч��
	wstring strXtqy; //ϡ����ҵ
};

struct DeviceInfo {

	string strOrdernumber; //���к�
	string strBusiId;// 1 - 135
	string strVender;// 0bda
	string strProduct;//5411
	string strInst_id;//null
	string strDeviceOperateEnum;// 0
	string strPortNum;// null
	string strIsExported;//false
};

struct deviceItem
{
	SStringT ordernumber;
	SStringT qymc;
	SStringT nsrbh;
	SStringT sksblx;
	SStringT fjh;
	SStringT jqbh;
	SStringT sbdkh;
	SStringT jgbh;
	SStringT operate;

	//�豸�˿ں�
	SStringT port;
	SStringT vender;
	SStringT product;
};

////
//string SeriesNum;
//string IP;
//string PROXY_IP;
//int     PROXY_PORT;
//string Gateway;
//string ConStatus;
//string SoftWareVer;
//string ProtocolVer;
//string NSRSBH;
//string NSRMC;
//int     FJH;
//string FPZL;
//int     SFDBSQ;
//int     SFDSSQ;
//int     CBZT;
//string BZ;
////
struct JQXXItem
{
	SStringT PGBM; //�̹�����
	SStringT JQBH; //�������
	SStringT ConStatus; //�̹�״̬
	SStringT IP; //�̹�״̬
	SStringT ConMac; //�̹�״̬
	SStringT SoftWareVer; //����汾
	SStringT bindNum; //��˰����
	SStringT MQttStatus; //MQtt
};

struct PanZUItem
{
	int     FJH; //�ֻ���
	SStringT Ip; //Ip
	SStringT PanGuialias; //�̹����
	SStringT PanGNum; //�̹���
	SStringT port; //�˿ں�
	SStringT strNSRMC; //��������(��˰������)
	SStringT strNSRSBH; //����˰��(��˰��ʶ���)
	SStringT strJSPBH; //�������(��˰�̱��)
	SStringT strBDZT; //˰�̰�״̬
	SStringT strPTCS; //ƽ̨����״̬ (ƽ̨����)
	SStringT strJDCS; //�ֶ�����״̬ (ssl����)

};

struct  tagCerInfo
{
	string  mPwd;
	string mNewpwd;
	string plat_addr;//ƽ̨��ַ
	string le_plat_platcode; //��Ʊƽ̨����
	string le_plat_authorizationcode; //��Ȩ��
	string le_plat_registrationcode; //ע����
	string le_plat_thirdplatcode; //������ƽ̨����
	string sever_addr;//��������ַ
	string sever_port;//�������˿�
	string auth_addr;//��ѡ��֤��ַ
};


