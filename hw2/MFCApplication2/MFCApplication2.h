
// MFCApplication2.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCApplication2App: 
// �аѾ\��@�����O�� MFCApplication2.cpp
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;