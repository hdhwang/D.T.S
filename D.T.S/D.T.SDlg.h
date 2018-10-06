
// D.T.SDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"
#include "afxext.h"


// CDTSDlg 대화 상자
class CDTSDlg : public CDialogEx
{
// 생성입니다.
public:
	CDTSDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DTS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic fanta;
	CBitmapButton reglimitbutton;
	afx_msg void OnBnClickedButton1();
	CBitmapButton dislimitbutton;
	afx_msg void OnBnClickedButton2();
	CBitmapButton cmdlimitbutton;
	CBitmapButton startlimitbutton;
	afx_msg void OnBnClickedButton4();
	CBitmapButton drivelimitbutton;
	CBitmapButton controllimitbutton;
	afx_msg void OnBnClickedButton6();
	CBitmapButton regallowbutton;
	CBitmapButton disallowbutton;
	CBitmapButton cmdallowbutton;
	CBitmapButton startallowbutton;
	CBitmapButton driveallowbutton;
	CBitmapButton controlallowbutton;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton5();
};
