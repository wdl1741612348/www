
// DB0505-3.h : DB0505-3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CDB05053App:
// �йش����ʵ�֣������ DB0505-3.cpp
//

class CDB05053App : public CWinApp
{
public:
	CDB05053App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDB05053App theApp;
