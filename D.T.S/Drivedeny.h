#pragma once
#include "afxwin.h"


// Drivedeny ��ȭ �����Դϴ�.

class Drivedeny : public CDialogEx
{
	DECLARE_DYNAMIC(Drivedeny)

public:
	Drivedeny(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Drivedeny();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
	CComboBox seldrive;
};
