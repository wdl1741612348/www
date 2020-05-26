
// MFC01View.cpp : CMFC01View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFC01.h"
#endif

#include "MFC01Doc.h"
#include "MFC01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC01View

IMPLEMENT_DYNCREATE(CMFC01View, CView)

BEGIN_MESSAGE_MAP(CMFC01View, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CMFC01View ����/����

CMFC01View::CMFC01View()
{
	// TODO: �ڴ˴���ӹ������
	set = true;
	N = 5;
	
	for (int i = 0; i < N; i++)
	{
		int t = (i + 1) * 200;  //ÿһ��Բ�����Ͻǵ�λ��
		CRect rect(t, 0, t + 80, 80);  //���Ͻǵ����꣬�����½ǵ�����
		cr.Add(rect);
		K = 0;
	}

}

CMFC01View::~CMFC01View()
{
}

BOOL CMFC01View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFC01View ����

void CMFC01View::OnDraw(CDC* pDC)
{
	CMFC01Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
		return;
	if (set)
	{
		for (int i = 0; i < N; i++)
		{
			SetTimer(i, rand() % 400 + 100, NULL); //��i����ʱ�����Ժ�����㣬1000�������һ�룻
		}
		set = false;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < N; i++)
	{
		pDC->Ellipse(cr[i]);
	}
}


// CMFC01View ���

#ifdef _DEBUG
void CMFC01View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC01View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC01Doc* CMFC01View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC01Doc)));
	return (CMFC01Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC01View ��Ϣ�������


void CMFC01View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int i = nIDEvent; //��ʾ�ǵڼ�����ʱ��
	CRect m_cr;
	GetClientRect(&m_cr);
	if (cr[i].bottom < m_cr.bottom && K== 0)
	{
		cr[i].top += 10;
		cr[i].bottom += 10;
		Invalidate();
	}
	if (cr[i].bottom > m_cr.bottom || cr[i].bottom == m_cr.bottom)

		K = 1;

	if (cr[i].top > m_cr.top && K == 1)
	{
		cr[i].top -= 10;
		cr[i].bottom -= 10;
		Invalidate();
	}

	CView::OnTimer(nIDEvent);
}
