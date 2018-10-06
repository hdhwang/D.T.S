
// D.T.SDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "D.T.S.h"
#include "D.T.SDlg.h"
#include "afxdialogex.h"
#include "Drivedeny.h"
#include "Driveallow.h"

Drivedeny dlg1;
Driveallow dlg2;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDTSDlg 대화 상자




CDTSDlg::CDTSDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDTSDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDTSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, fanta);
	DDX_Control(pDX, IDC_BUTTON1, reglimitbutton);
	DDX_Control(pDX, IDC_BUTTON2, dislimitbutton);
	DDX_Control(pDX, IDC_BUTTON3, cmdlimitbutton);
	DDX_Control(pDX, IDC_BUTTON4, startlimitbutton);
	DDX_Control(pDX, IDC_BUTTON5, drivelimitbutton);
	DDX_Control(pDX, IDC_BUTTON6, controllimitbutton);
	DDX_Control(pDX, IDC_BUTTON10, regallowbutton);
	DDX_Control(pDX, IDC_BUTTON11, disallowbutton);
	DDX_Control(pDX, IDC_BUTTON12, cmdallowbutton);
	DDX_Control(pDX, IDC_BUTTON7, startallowbutton);
	DDX_Control(pDX, IDC_BUTTON8, driveallowbutton);
	DDX_Control(pDX, IDC_BUTTON9, controlallowbutton);
}

BEGIN_MESSAGE_MAP(CDTSDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CDTSDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDTSDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CDTSDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDTSDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON10, &CDTSDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON3, &CDTSDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON11, &CDTSDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CDTSDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON7, &CDTSDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDTSDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDTSDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON5, &CDTSDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CDTSDlg 메시지 처리기

BOOL CDTSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	HBITMAP hbit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	fanta.SetBitmap(hbit);

	CRect rt;
	GetClientRect(&rt);
	fanta.SetWindowPos(NULL,0,0,rt.Width(), rt.Height(), SWP_SHOWWINDOW);
	reglimitbutton.LoadBitmaps(IDB_BITMAP2, IDB_BITMAP8, NULL, NULL );
	reglimitbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	dislimitbutton.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP9, NULL, NULL );
	dislimitbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	cmdlimitbutton.LoadBitmaps(IDB_BITMAP4, IDB_BITMAP10, NULL, NULL );
	cmdlimitbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	startlimitbutton.LoadBitmaps(IDB_BITMAP5, IDB_BITMAP11, NULL, NULL );
	startlimitbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	drivelimitbutton.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP12, NULL, NULL );
	drivelimitbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	controllimitbutton.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP13, NULL, NULL );
	controllimitbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.


	regallowbutton.LoadBitmaps(IDB_BITMAP2, IDB_BITMAP8, NULL, NULL );
	regallowbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	disallowbutton.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP9, NULL, NULL );
	disallowbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	cmdallowbutton.LoadBitmaps(IDB_BITMAP4, IDB_BITMAP10, NULL, NULL );
	cmdallowbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	startallowbutton.LoadBitmaps(IDB_BITMAP5, IDB_BITMAP11, NULL, NULL );
	startallowbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	driveallowbutton.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP12, NULL, NULL );
	driveallowbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.
	controlallowbutton.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP13, NULL, NULL );
	controlallowbutton.SizeToContent(); // 버튼을 이미지의 크기에 맞게 조절합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CDTSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDTSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDTSDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 레지스트리 편집기 제한
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isDisableRegistryTools;
    DWORD disable=1;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("DisableRegistryTools"), NULL , &dwType , (LPBYTE)&isDisableRegistryTools , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"));
	RegKey.SetValue(disable, _T("DisableRegistryTools"));
    RegKey.Close();
	
	
	MessageBox((_T("레지스트리 편집기를 제한하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);

}


void CDTSDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 디스플레이 제한
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isnodispcpl;
    DWORD disable=1;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("nodispcpl"), NULL , &dwType , (LPBYTE)&isnodispcpl , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"));
	RegKey.SetValue(disable, "nodispcpl");
    RegKey.Close();
	
	
	MessageBox((_T("디스플레이 변경을 제한하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 시작 - 실행 제한
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isNoRun;
    DWORD disable=1;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("NoRun"), NULL , &dwType , (LPBYTE)&isNoRun , &dwSize);
    }
    RegKey.Create(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer"));
	RegKey.SetValue(disable, _T("NoRun"));
    RegKey.Close();
	
	
	MessageBox((_T("시작 - 실행 접근을 제한하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);

}


void CDTSDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 제어판 제한
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isNoControlPanel;
    DWORD disable=1;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("NoControlPanel"), NULL , &dwType , (LPBYTE)&isNoControlPanel , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"));
	RegKey.SetValue(disable, _T("NoControlPanel"));
    RegKey.Close();
	
	
	MessageBox((_T("제어판 접근을 제한하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 레지스트리 편집기 허용

	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isDisableRegistryTools;
    DWORD disable=0;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("DisableRegistryTools"), NULL , &dwType , (LPBYTE)&isDisableRegistryTools , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"));
	RegKey.SetValue(disable, _T("DisableRegistryTools"));
    RegKey.Close();
	
	
	MessageBox((_T("레지스트리 편집기 접근을 허용하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 명령프롬프트 제한
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isNoCMD;
    DWORD disable=1;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Policies\\Microsoft\\Windows\\System"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("DisableCMD"), NULL , &dwType , (LPBYTE)&isNoCMD , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Policies\\Microsoft\\Windows\\System"));
	RegKey.SetValue(disable, _T("DisableCMD"));
    RegKey.Close();
	
	
	MessageBox((_T("명령프롬프트 접근을 제한하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 디스플레이 허용

	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isnodispcpl;
    DWORD disable=0;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("nodispcpl"), NULL , &dwType , (LPBYTE)&isnodispcpl , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\system"));
	RegKey.SetValue(disable, _T("nodispcpl"));
    RegKey.Close();
	
	
	MessageBox((_T("디스플레이 변경을 허용하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 명령프롬프트 허용

	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isNoCMD;
    DWORD disable=0;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Policies\\Microsoft\\Windows\System"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("DisableCMD"), NULL , &dwType , (LPBYTE)&isNoCMD , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Policies\\Microsoft\\Windows\\System"));
	RegKey.SetValue(disable, _T("DisableCMD"));
    RegKey.Close();
	
	
	MessageBox((_T("명령프롬프트 접근을 허용하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 시작 - 실행 허용
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isNoRun;
    DWORD disable=0;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("NoRun"), NULL , &dwType , (LPBYTE)&isNoRun , &dwSize);
    }
    RegKey.Create(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer"));
	RegKey.SetValue(disable, _T("NoRun"));
    RegKey.Close();
	
	
	MessageBox((_T("시작 - 실행 접근을 허용하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int res=dlg2.DoModal();
}


void CDTSDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// 제어판 허용
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD isNoControlPanel;
    DWORD disable=0;
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("NoControlPanel"), NULL , &dwType , (LPBYTE)&isNoControlPanel , &dwSize);
    }
    RegKey.Create(HKEY_CURRENT_USER, _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer"));
	RegKey.SetValue(disable, _T("NoControlPanel"));
    RegKey.Close();
	
	
	MessageBox((_T("제어판 접근을 허용하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int res=dlg1.DoModal();
}
