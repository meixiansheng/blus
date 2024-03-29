// CloundBoxLoginDlg.h : interface of the CloundBoxLoginDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "stdafx.h"

class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose()
	{
		AnimateHostWindow(200, AW_CENTER | AW_HIDE);
		DestroyWindow();
	}
	void OnMaximize()
	{
		SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
	}
	void OnRestore()
	{
		SendMessage(WM_SYSCOMMAND, SC_RESTORE);
	}
	void OnMinimize()
	{
		SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
	}

	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnBtnSetting();
	void OnBtnSettingOK();
	void OnBtnSettingCancel();
	void OnBtnLogin();
	void OnBtnCheck();
	void OnLocalLogin();


	int  GetReturnCode() { return m_nRetCode; }

private:
	void verify();

protected:

	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_setting", OnBtnSetting)
		EVENT_NAME_COMMAND(L"btn_setting_ok", OnBtnSettingOK)
		EVENT_NAME_COMMAND(L"btn_setting_cancel", OnBtnSettingCancel)
		EVENT_NAME_COMMAND(L"btn_login", OnBtnLogin)
		EVENT_NAME_COMMAND(L"save_password_check", OnBtnCheck)
		EVENT_NAME_COMMAND(L"link_localLogon", OnLocalLogin)
		EVENT_MAP_END()

		BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
		END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	BOOL            m_bCheck;

	int             m_nRetCode;
	int             m_index;

	SStringT m_collectorPath;
	SStringT mCurUsername;
};
