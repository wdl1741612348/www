
// exp14-2-1.h : exp14-2-1 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cexp1421App:
// �йش����ʵ�֣������ exp14-2-1.cpp
//

class Cexp1421App : public CWinApp
{
public:
	Cexp1421App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cexp1421App theApp;
