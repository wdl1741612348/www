
// exp14-2-3.h : exp14-2-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp1423App:
// �йش����ʵ�֣������ exp14-2-3.cpp
//

class Cexp1423App : public CWinApp
{
public:
	Cexp1423App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp1423App theApp;
