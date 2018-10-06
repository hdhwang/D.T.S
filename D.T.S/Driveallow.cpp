// Driveallow.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "D.T.S.h"
#include "Driveallow.h"
#include "afxdialogex.h"
CString seldrive3=_T("empty");


int square2(int x, int z){
	int i;
	int y = x;
	for(i=0 ; i < z; i++){
		x*=y;
	}
	return x;
}

// Driveallow ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(Driveallow, CDialogEx)

Driveallow::Driveallow(CWnd* pParent /*=NULL*/)
	: CDialogEx(Driveallow::IDD, pParent)
{

}

Driveallow::~Driveallow()
{
}

void Driveallow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, seldrive);
	CString strDrive;    // ���� ����̺�� �ӽ� ����
	TCHAR pTmp[256];
	memset(pTmp, '\0', 256);
	GetLogicalDriveStrings(256, pTmp);
	
	for(int i=0 ; i<256 ; i++) {
		if(pTmp[i] == '\0' && pTmp[i+1] == '\0')
		break;
		

		strDrive.Empty();
		
		while(pTmp[i] != '\0')
			strDrive += pTmp[i++];
		
		if(GetDriveType(strDrive) != DRIVE_CDROM && GetDriveType(strDrive) != DRIVE_REMOVABLE) {
			seldrive.AddString(strDrive);
			if(strcmp((LPSTR)(LPCTSTR)seldrive3,"empty")==0){
				seldrive3 = strDrive;
			}
		}
	}
	seldrive.SetCurSel(0);
}


BEGIN_MESSAGE_MAP(Driveallow, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Driveallow::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &Driveallow::OnBnClickedOk)
END_MESSAGE_MAP()


// Driveallow �޽��� ó�����Դϴ�.


void Driveallow::OnCbnSelchangeCombo1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int curSel=seldrive.GetCurSel();
	//�޺� �ڽ��� �ش� �ε��� ��ġ�� �׸� ���� ���´�.
	seldrive.GetLBText(curSel, seldrive3);
}


void Driveallow::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int defaultkey=0;
	int key = 0;
	char SelectDrive = 'A';
	CString minus=_T(":\"");
	seldrive3 = seldrive3.Left(seldrive3.GetLength() - minus.GetLength()); // C:\���� :\�� ��� ����
	for( int i = 0 ; i<25; i++){ 
		if(seldrive3 == SelectDrive){
			key = 1;
		}
		else if(seldrive3 == SelectDrive + (int)i+1){
			key = square2(2,i);
		}
	}
		
	DWORD dwType = REG_DWORD;
    HKEY hKey;
    DWORD NoDrives;
	DWORD NoViewOnDrive;
    
    DWORD dwSize = sizeof(DWORD);
    CRegKey RegKey;
    LONG lResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\windows\\CurrentVersion\\Policies\\Explorer"), 0 , KEY_READ , &hKey);
    if(lResult == ERROR_SUCCESS)
    {
        RegQueryValueEx(hKey, _T("NoDrives"), NULL , &dwType , (LPBYTE)&NoDrives , &dwSize);
		RegQueryValueEx(hKey, _T("NoViewOnDrive"), NULL , &dwType , (LPBYTE)&NoViewOnDrive , &dwSize);
		defaultkey = (int)NoViewOnDrive;
		key = defaultkey - key;
		if(key<0){
			key=0;
		}
    }
    DWORD drive = key;
	RegKey.Create(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\windows\\CurrentVersion\\Policies\\Explorer"));
	RegKey.SetValue(drive, _T("NoDrives"));
	RegKey.SetValue(drive, _T("NoViewOnDrive"));
    RegKey.Close();
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	MessageBox(seldrive3+(_T(" ����̺��� ������ ����Ͽ����ϴ�.")),
			  _T("����"),
			  MB_OK|MB_ICONINFORMATION
	);
	CDialogEx::OnOK();
}
