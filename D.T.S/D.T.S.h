
// D.T.S.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CDTSApp:
// �� Ŭ������ ������ ���ؼ��� D.T.S.cpp�� �����Ͻʽÿ�.
//

class CDTSApp : public CWinApp
{
public:
	CDTSApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CDTSApp theApp;