
// D.T.SDlg.h : ��� ����
//

#pragma once
#include "afxwin.h"
#include "afxext.h"


// CDTSDlg ��ȭ ����
class CDTSDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CDTSDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DTS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
