// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#include "MainDlg.h"
#include "process/global.h"
#include "middle/db/dbtable_userinfo.h"
#include "Dlg/DlgWaringLog.h"

#include <time.h>
#include <dwmapi.h>
#include <atlconv.h>
#pragma comment(lib,"dwmapi.lib")

CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_CLOUNDBOXLOGIN"))
{
	m_nRetCode = -1;
	m_bLayoutInited = FALSE;

	m_bCheck = FALSE;

	m_index = 0;
}

CMainDlg::~CMainDlg()
{
}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;

	SetPropW(m_hWnd, _T("40125B5F-6825-4654-8BCF-6417B0AF489A"), HANDLE(1775180400));

	USES_CONVERSION;
	//取得最近5次使用的用户名
	WCHAR szPath[1024] = { 0 };
	::GetModuleFileName(NULL, szPath, sizeof(szPath) - 1);
	::PathRemoveFileSpec(szPath);
	m_collectorPath = szPath;
	m_collectorPath.Append(L"\\collector.ini");

	int i;
	SStringT strname;
	SStringT strPassWord;

	WCHAR username[256];
	for (i = 6; i > 0; i--)
	{
		strname.Format(L"username%d", i);
		GetPrivateProfileString(L"LoginInfo", strname, L"", username, 32, m_collectorPath);
		if (strlen(W2A(username))>0)
		{
			m_index = i;
			mCurUsername = username;
			break;
		}
	}

	SRichEdit * edtAccount = FindChildByName2<SRichEdit>(L"edit_account");
	if (edtAccount)
	{
		edtAccount->SetWindowText(username);
	}

	SRichEdit * edtPassword = FindChildByName2<SRichEdit>(L"edit_password");
	if (edtPassword)
	{
		edtPassword->SetAttribute(L"wordWrap", TRUE);
	}


	WCHAR savePassword[256];
	SStringT strSavePassword;
	GetPrivateProfileString(L"LoginInfo", L"SavePassword", L"", savePassword, 32, m_collectorPath);
	strSavePassword = savePassword;
	if (strSavePassword == L"1") 
	{
		m_bCheck = true;
		strPassWord.Format(L"password%d", m_index);
		GetPrivateProfileString(L"LoginInfo", strPassWord, L"", savePassword, 32, m_collectorPath);
		if (edtPassword)
		{
			edtPassword->SetWindowText(savePassword);
		}
	}
	else
	{
		m_bCheck = false;
	}

	
	SCheckBox * pSave = FindChildByName2<SCheckBox>(L"save_password_check");
	if (pSave)
	{
		if (m_bCheck)
		{
			pSave->SetCheck(TRUE);
		}
		else
		{
			pSave->SetCheck(FALSE);
		}
	}

	return 0;
}

void CMainDlg::OnBtnSetting()
{

}

void CMainDlg::OnBtnSettingOK()
{

}

void CMainDlg::OnBtnSettingCancel()
{

}

void CMainDlg::OnBtnLogin()
{
	verify();
}

void CMainDlg::OnBtnCheck()
{
	SCheckBox * pSave = FindChildByName2<SCheckBox>(L"save_password_check");
	if (pSave)
	{
		if (pSave->IsChecked())
		{
			m_bCheck = TRUE;
		}
		else
		{
			m_bCheck = FALSE;
		}
	}

	LPCWSTR value = m_bCheck ? L"1" : L"0";
	WritePrivateProfileString(L"LoginInfo", L"SavePassword", value, m_collectorPath);

}

void CMainDlg::OnLocalLogin()
{
	m_nRetCode = 0;
	OnClose();
}

void CMainDlg::verify()
{
	SRichEdit * edtAccount = FindChildByName2<SRichEdit>(L"edit_account");
	SRichEdit * edtPassword = FindChildByName2<SRichEdit>(L"edit_password");
	if (!edtAccount || !edtPassword)
	{
		return;
	}

	USES_CONVERSION;

	string account, password;
	account = W2A(edtAccount->GetWindowText());;
	password = W2A(edtPassword->GetWindowText());

	if (account == "" || password == "")
	{
		SStringT strInfo = _T("账号密码不能为空！");
		DlgWaringLog dlg(strInfo);
		dlg.DoModal();
		return;
	}

	DBTable_UserInfo dbUserInfo;
	DB_USERINFO _userInfo;
	dbUserInfo.getPwdByUserName(account, _userInfo);

	if (password == _userInfo.Passwd)
	{
		Global::g_CurrentUser = _userInfo;
		/*if (Global::g_pMainWidget != nullptr)
		Global::g_pMainWidget->refrush();
		this->accept();*/
		m_nRetCode = 0;
		OnClose();

		for (int i = 1; i <= m_index; ++i)
		{
			SStringT strUserName;
			WCHAR username[256];
			strUserName.Format(L"username%d", i);
			GetPrivateProfileString(L"LoginInfo", strUserName, L"", username, 32, m_collectorPath);
			if (account == W2A(username))
			{
				SStringT strPassword;
				strPassword.Format(L"password%d", i);
				WritePrivateProfileString(L"LoginInfo", strPassword, A2W(password.c_str()), m_collectorPath);
				return;
			}

		}

		SStringT strUserName;
		strUserName.Format(L"username%d", m_index + 1);

		SStringT strPassword;
		strPassword.Format(L"password%d", m_index + 1);

		WritePrivateProfileString(L"LoginInfo", strUserName, A2W(account.c_str()), m_collectorPath);
		WritePrivateProfileString(L"LoginInfo", strPassword, A2W(password.c_str()), m_collectorPath);
	}
	else
	{
		SStringT strInfo = _T("账号或密码不正确！");
		DlgWaringLog dlg(strInfo);
		dlg.DoModal();
	}
}