
// exp14-2-2.h : exp14-2-2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp1422App:
// �йش����ʵ�֣������ exp14-2-2.cpp
//

class Cexp1422App : public CWinApp
{
public:
	Cexp1422App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp1422App theApp;
