#pragma once
#include "afxwin.h"


// Driveallow ��ȭ �����Դϴ�.

class Driveallow : public CDialogEx
{
	DECLARE_DYNAMIC(Driveallow)

public:
	Driveallow(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Driveallow();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox seldrive;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnBnClickedOk();
};
