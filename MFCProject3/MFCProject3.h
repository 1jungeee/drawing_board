
// MFCProject3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFCProject3App:
// �� Ŭ������ ������ ���ؼ��� MFCProject3.cpp�� �����Ͻʽÿ�.
//

class CMFCProject3App : public CWinApp
{
public:
	CMFCProject3App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFCProject3App theApp;