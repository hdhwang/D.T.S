#pragma once
#include "afxwin.h"


// Drivedeny 대화 상자입니다.

class Drivedeny : public CDialogEx
{
	DECLARE_DYNAMIC(Drivedeny)

public:
	Drivedeny(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Drivedeny();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	CComboBox seldrive;
};
