
// ��ɫ.h : ��ɫ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ɫApp:
// �йش����ʵ�֣������ ��ɫ.cpp
//

class C��ɫApp : public CWinApp
{
public:
	C��ɫApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ɫApp theApp;
