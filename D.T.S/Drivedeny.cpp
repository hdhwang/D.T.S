// Drivedeny.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "D.T.S.h"
#include "Drivedeny.h"
#include "afxdialogex.h"
CString seldrive2=_T("empty");

// Drivedeny 대화 상자입니다.

IMPLEMENT_DYNAMIC(Drivedeny, CDialogEx)

int square(int x, int z){
	int i;
	int y = x;
	for(i=0 ; i < z; i++){
		x*=y;
	}
	return x;
}



Drivedeny::Drivedeny(CWnd* pParent /*=NULL*/)
	: CDialogEx(Drivedeny::IDD, pParent)
{

}

Drivedeny::~Drivedeny()
{
}

void Drivedeny::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, seldrive);

	CString strDrive;    // 논리적 드라이브명 임시 저장
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
			if(strcmp((LPSTR)(LPCTSTR)seldrive2,"empty")==0){
				seldrive2 = strDrive;
			}
		}

	}
	seldrive.SetCurSel(0);
	DDX_Control(pDX, IDC_COMBO1, seldrive);

}


BEGIN_MESSAGE_MAP(Drivedeny, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Drivedeny::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &Drivedeny::OnBnClickedOk)
END_MESSAGE_MAP()


// Drivedeny 메시지 처리기입니다.


void Drivedeny::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int curSel=seldrive.GetCurSel();
	//콤보 박스의 해당 인덱스 위치의 항목 값을 얻어온다.
	seldrive.GetLBText(curSel, seldrive2);
}


void Drivedeny::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int defaultkey=0;
	int key = 0;
	char SelectDrive = 'A';
	CString minus=_T(":\"");
	seldrive2 = seldrive2.Left(seldrive2.GetLength() - minus.GetLength()); // C:\에서 :\를 배기 위해
	for( int i = 0 ; i<25; i++){ 
		if(seldrive2 == SelectDrive){
			key = 1;
		}
		else if(seldrive2 == SelectDrive + (int)i+1){
			key = square(2,i);
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
		key += defaultkey;
    }

    DWORD drive = key;
	RegKey.Create(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\Microsoft\\windows\\CurrentVersion\\Policies\\Explorer"));
	RegKey.SetValue(drive, _T("NoDrives"));
	RegKey.SetValue(drive, _T("NoViewOnDrive"));
    RegKey.Close();
	
	
	MessageBox(seldrive2+(_T(" 드라이브의 접근을 제한하였습니다.")),
			  _T("성공"),
			  MB_OK|MB_ICONINFORMATION
	);
	CDialogEx::OnOK();
}
