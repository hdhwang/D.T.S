#pragma once
#include "afxwin.h"


// Driveallow 대화 상자입니다.

class Driveallow : public CDialogEx
{
	DECLARE_DYNAMIC(Driveallow)

public:
	Driveallow(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Driveallow();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox seldrive;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
};
