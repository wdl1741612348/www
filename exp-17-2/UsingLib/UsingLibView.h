
// UsingLibView.h : CUsingLibView ��Ľӿ�
//

#pragma once


class CUsingLibView : public CView
{
protected: // �������л�����
	CUsingLibView();
	DECLARE_DYNCREATE(CUsingLibView)

// ����
public:
	CUsingLibDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CUsingLibView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // UsingLibView.cpp �еĵ��԰汾
inline CUsingLibDoc* CUsingLibView::GetDocument() const
   { return reinterpret_cast<CUsingLibDoc*>(m_pDocument); }
#endif

