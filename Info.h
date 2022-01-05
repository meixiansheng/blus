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
	wstring strReturncode; //返回代码
	wstring strReturnmsg; //返回信息
	wstring strSksbbh; //税控设备编号
	wstring strNsrsbh; //纳税人识别号
	wstring strNsrmc; //纳税人名称
	wstring strSwjgdm; //税务机关代码
	wstring strSwjgmc; //税务机关名称
	wstring strFplxdm; //发票类型代码
	wstring strDqsz; //当前时钟
	wstring strDjsj; //登记时间
	wstring strBbh; //版本号
	wstring strKpjh; //开票机号
	wstring strQylx; //企业类型
	wstring strDjxh; //登记序号
	wstring strKpbz; //开票标志
	wstring strTdqy; //特定企业
	wstring strNcpqy; //农产品企业
	wstring strDxqy; //电信企业
	wstring strXgmkjzpbs; //小规模开具专票标识
	wstring strEsjdcbz; //二手机动车标志	
	wstring strCpybs; //成品油标识
	wstring strCpybsyxq; //成品油标识有效期
	wstring strCpybmdbs; //成品油白名单标识
	wstring strCpybmdbsyxq; //成品油白名单有效期
	wstring strXtqy; //稀土企业
};

struct DeviceInfo {

	string strOrdernumber; //序列号
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

	//设备端口号
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
	SStringT PGBM; //盘柜总数
	SStringT JQBH; //机器编号
	SStringT ConStatus; //盘柜状态
	SStringT IP; //盘柜状态
	SStringT ConMac; //盘柜状态
	SStringT SoftWareVer; //软件版本
	SStringT bindNum; //绑定税盘数
	SStringT MQttStatus; //MQtt
};

struct PanZUItem
{
	int     FJH; //分机号
	SStringT Ip; //Ip
	SStringT PanGuialias; //盘柜别名
	SStringT PanGNum; //盘柜编号
	SStringT port; //端口号
	SStringT strNSRMC; //销方名称(纳税人名称)
	SStringT strNSRSBH; //销方税号(纳税人识别号)
	SStringT strJSPBH; //机器编号(金税盘编号)
	SStringT strBDZT; //税盘绑定状态
	SStringT strPTCS; //平台连接状态 (平台测试)
	SStringT strJDCS; //局端连接状态 (ssl测试)

};

struct  tagCerInfo
{
	string  mPwd;
	string mNewpwd;
	string plat_addr;//平台地址
	string le_plat_platcode; //开票平台编码
	string le_plat_authorizationcode; //授权码
	string le_plat_registrationcode; //注册码
	string le_plat_thirdplatcode; //第三方平台编码
	string sever_addr;//服务器地址
	string sever_port;//服务器端口
	string auth_addr;//勾选认证地址
};


