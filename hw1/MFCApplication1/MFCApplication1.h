
// MFCApplication1.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CMFCApplication1App: 
// �аѾ\��@�����O�� MFCApplication1.cpp
//

class CMFCApplication1App : public CWinApp
{
public:
	CMFCApplication1App();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1App theApp;