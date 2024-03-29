// dui-demo.cpp : main source file
//
#include "Info.h"
#include "control/SIPAddressCtrl.h"
#include "control/SGifPlayer.h"
#include "../controls.extend/SVscrollbar.h"
#include "../controls.extend/SSkinNewScrollBar.h"
#include "Upgrade/filesmd5checkadapter.h"
#include "Upgrade/CheckUpdateLib.h"

#include "MainDlg.h"
#include "Dlg/CloundBoxDlg.h"
#include <io.h>
//从PE文件加载，注意从文件加载路径位置
#define RES_TYPE 0
//#define SYSRES_TYPE 0
// #define RES_TYPE 0   //PE
// #define RES_TYPE 1   //ZIP
// #define RES_TYPE 2   //7z
// #define RES_TYPE 2   //文件
//去掉多项支持，以免代码显得混乱
#include "../components/resprovider-zip/zipresprovider-param.h"
#include "../controls.extend/smiley/ssmileyctrl.h"
#if (RES_TYPE==1)
#include "resprovider-zip\zipresprovider-param.h"
#else 
#if (RES_TYPE==2)
#include "resprovider-7zip\zip7resprovider-param.h"
#endif
#endif
#ifdef _DEBUG
#define SYS_NAMED_RESOURCE _T("soui-sys-resourced.dll")
#else
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#endif


//定义唯一的一个R,UIRES对象,ROBJ_IN_CPP是resource.h中定义的宏。
ROBJ_IN_CPP

// 此代码模块中包含的函数的前向声明:
BOOL CALLBACK OnEnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	HANDLE hTemp = ::GetPropW(hWnd, _T("40125B5F-6825-4654-8BCF-6417B0AF489A"));
	if (NULL != hTemp && (HANDLE)1775180400 == hTemp)
	{
		*(HWND*)lParam = hWnd;
		return FALSE;
	}
	return TRUE;
}

BOOL CALLBACK OnEnumWindowsProc1(HWND hWnd, LPARAM lParam)
{
	HANDLE hTemp = ::GetPropW(hWnd, _T("40125B5F-6825-4654-8BCF-6417B0AF489B"));
	if (NULL != hTemp && (HANDLE)1775180401 == hTemp)
	{
		*(HWND*)lParam = hWnd;
		return FALSE;
	}
	return TRUE;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int /*nCmdShow*/)
{   
	HRESULT hRes = OleInitialize(NULL);
	SASSERT(SUCCEEDED(hRes));	

	//检测 客户端(登录界面)
	HWND hOldWnd = NULL;
	::EnumWindows(OnEnumWindowsProc, (LPARAM)&hOldWnd);
	if (NULL != hOldWnd)
	{
		::ShowWindow(hOldWnd, SW_SHOWNORMAL);
		::SetForegroundWindow(hOldWnd);
		return 0;
	}

	//检测 客户端(主界面)
	hOldWnd = NULL;
	::EnumWindows(OnEnumWindowsProc1, (LPARAM)&hOldWnd);
	if (NULL != hOldWnd)
	{
		::ShowWindow(hOldWnd, SW_SHOWNORMAL);
		::SetForegroundWindow(hOldWnd);
		return 0;
	}

#ifndef _DEBUG
	///升级
	//更新升级模块
	CheckUpdateLib _checkUpdateLib;
	_checkUpdateLib.UpdateLib();

	std::string _curVer = SOFTWARE_VERSION;
	_curVer.erase(3, 1);
	_curVer.erase(4, 1);

	//判断是否需要升级

	bool isUpdate = _checkUpdateLib.YesNoCheck(SoftwareVerID, PT_SERVICE, _curVer);
	if (isUpdate)
	{
		filesmd5checkadapter _zutil;
		string strPath = _zutil.GetInstallPathGBK();
		wstring strFullPath = _zutil.s2ws(strPath).append(_T("\\")).append(_T(PT_UPDATE_SELF));

		if ((_access(S_CW2A(strFullPath.c_str()), 0)) != -1)
		{
			/*软件更新程序命令行参数例如：988684118662619136;BillingService.exe;1.011*/
			string _cmdline = SoftwareVerID;
			_cmdline.append(";").append(PT_SERVICE).append(";").append(_curVer);
			ShellExecute(NULL, _T("open"), strFullPath.c_str(), S_CA2W(_cmdline.c_str()), S_CA2W(strPath.c_str()), SW_SHOWNORMAL);
		}
	}
#endif	

	int nRet = 0;

	SComMgr *pComMgr = new SComMgr;
	TCHAR szCurrentDir[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));

	LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('\\'));
#ifdef _DEBUG
	_tcscpy(lpInsertPos + 1, _T("ManageTool"));
#else
	_tcscpy(lpInsertPos + 1, _T("\0"));
#endif
	SetCurrentDirectory(szCurrentDir);
	{
		BOOL bLoaded = FALSE;  
		CAutoRefPtr<SOUI::IImgDecoderFactory> pImgDecoderFactory;
		CAutoRefPtr<SOUI::IRenderFactory> pRenderFactory;
		bLoaded = pComMgr->CreateRender_GDI((IObjRef**)&pRenderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [render] failed!"));
		bLoaded = pComMgr->CreateImgDecoder((IObjRef**)&pImgDecoderFactory);
		SASSERT_FMT(bLoaded, _T("load interface [%s] failed!"), _T("imgdecoder"));

		pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
		SApplication *theApp = new SApplication(pRenderFactory, hInstance);
	    theApp->RegisterWindowClass<SIPAddressCtrl>();//注册IP控件
		theApp->RegisterSkinClass<SSkinVScrollbar>();//注册纵向滚动条皮肤
		theApp->RegisterSkinClass<SSkinNewScrollbar>();//注册纵向滚动条皮肤
		theApp->RegisterWindowClass<SGifPlayer>();//注册gif
		theApp->RegisterSkinClass<SSkinGif>();//注册SkinGif
		
#ifdef _DEBUG
		//选择了仅在Release版本打包资源则系统资源在DEBUG下始终使用DLL加载
		{
			HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
			if (hModSysResource)
			{
				CAutoRefPtr<IResProvider> sysResProvider;
				CreateResProvider(RES_PE, (IObjRef**)&sysResProvider);
				sysResProvider->Init((WPARAM)hModSysResource, 0);
				theApp->LoadSystemNamedResource(sysResProvider);
				FreeLibrary(hModSysResource);
			}
			else
			{
				SASSERT(0);
			}
		}
#else		
		//从DLL加载系统资源
		{
			HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
			if (hModSysResource)
			{
				CAutoRefPtr<IResProvider> sysResProvider;
				CreateResProvider(RES_PE, (IObjRef**)&sysResProvider);
				sysResProvider->Init((WPARAM)hModSysResource, 0);
				theApp->LoadSystemNamedResource(sysResProvider);
				FreeLibrary(hModSysResource);
			}
			else
			{
				SASSERT(0);
			}
		}
#endif

		CAutoRefPtr<IResProvider>   pResProvider;

#ifdef _DEBUG		
		//选择了仅在Release版本打包资源则在DEBUG下始终使用文件加载
		{
			CreateResProvider(RES_FILE, (IObjRef**)&pResProvider);
			bLoaded = pResProvider->Init((LPARAM)_T("uires"), 0);
			SASSERT(bLoaded);
		}
#else
		{
			CreateResProvider(RES_PE, (IObjRef**)&pResProvider);
			bLoaded = pResProvider->Init((WPARAM)hInstance, 0);
			SASSERT(bLoaded);
		}
#endif
		theApp->InitXmlNamedID(namedXmlID, ARRAYSIZE(namedXmlID), TRUE);
		theApp->AddResProvider(pResProvider);
		// BLOCK: Run application
		{
			CMainDlg dlgMain;
			dlgMain.Create(GetActiveWindow());
			dlgMain.SendMessage(WM_INITDIALOG);
			dlgMain.CenterWindow(dlgMain.m_hWnd);
			dlgMain.ShowWindow(SW_SHOWNORMAL);
			nRet = theApp->Run(dlgMain.m_hWnd);

			if (dlgMain.GetReturnCode() == 0)
			{
				CloundBoxDlg chatFrame;
				chatFrame.Create(GetActiveWindow(), 0, 0, 0, 0);
				chatFrame.SendMessage(WM_INITDIALOG);
				chatFrame.CenterWindow(chatFrame.m_hWnd);

				chatFrame.ShowWindow(SW_SHOWNORMAL);
				nRet = theApp->Run(chatFrame.m_hWnd);
			}
		}

		delete theApp;
	}

	delete pComMgr;

	OleUninitialize();
	return nRet;
}
