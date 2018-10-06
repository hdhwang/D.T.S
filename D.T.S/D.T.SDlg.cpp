
// D.T.SDlg.cpp : ���� ����
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


// CDTSDlg ��ȭ ����




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


// CDTSDlg �޽��� ó����

BOOL CDTSDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	HBITMAP hbit = LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	fanta.SetBitmap(hbit);

	CRect rt;
	GetClientRect(&rt);
	fanta.SetWindowPos(NULL,0,0,rt.Width(), rt.Height(), SWP_SHOWWINDOW);
	reglimitbutton.LoadBitmaps(IDB_BITMAP2, IDB_BITMAP8, NULL, NULL );
	reglimitbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	dislimitbutton.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP9, NULL, NULL );
	dislimitbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	cmdlimitbutton.LoadBitmaps(IDB_BITMAP4, IDB_BITMAP10, NULL, NULL );
	cmdlimitbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	startlimitbutton.LoadBitmaps(IDB_BITMAP5, IDB_BITMAP11, NULL, NULL );
	startlimitbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	drivelimitbutton.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP12, NULL, NULL );
	drivelimitbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	controllimitbutton.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP13, NULL, NULL );
	controllimitbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.


	regallowbutton.LoadBitmaps(IDB_BITMAP2, IDB_BITMAP8, NULL, NULL );
	regallowbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	disallowbutton.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP9, NULL, NULL );
	disallowbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	cmdallowbutton.LoadBitmaps(IDB_BITMAP4, IDB_BITMAP10, NULL, NULL );
	cmdallowbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	startallowbutton.LoadBitmaps(IDB_BITMAP5, IDB_BITMAP11, NULL, NULL );
	startallowbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	driveallowbutton.LoadBitmaps(IDB_BITMAP6, IDB_BITMAP12, NULL, NULL );
	driveallowbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.
	controlallowbutton.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP13, NULL, NULL );
	controlallowbutton.SizeToContent(); // ��ư�� �̹����� ũ�⿡ �°� �����մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CDTSDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CDTSDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDTSDlg::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������Ʈ�� ������ ����
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
	
	
	MessageBox((_T("������Ʈ�� �����⸦ �����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);

}


void CDTSDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���÷��� ����
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
	
	
	MessageBox((_T("���÷��� ������ �����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���� - ���� ����
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
	
	
	MessageBox((_T("���� - ���� ������ �����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);

}


void CDTSDlg::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ ����
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
	
	
	MessageBox((_T("������ ������ �����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton10()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������Ʈ�� ������ ���

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
	
	
	MessageBox((_T("������Ʈ�� ������ ������ ����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���������Ʈ ����
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
	
	
	MessageBox((_T("���������Ʈ ������ �����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton11()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���÷��� ���

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
	
	
	MessageBox((_T("���÷��� ������ ����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton12()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���������Ʈ ���

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
	
	
	MessageBox((_T("���������Ʈ ������ ����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ���� - ���� ���
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
	
	
	MessageBox((_T("���� - ���� ������ ����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int res=dlg2.DoModal();
}


void CDTSDlg::OnBnClickedButton9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// ������ ���
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
	
	
	MessageBox((_T("������ ������ ����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
}


void CDTSDlg::OnBnClickedButton5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int res=dlg1.DoModal();
}
