
// ��ɫView.h : C��ɫView ��Ľӿ�
//

#pragma once


class C��ɫView : public CView
{
protected: // �������л�����
	C��ɫView();
	DECLARE_DYNCREATE(C��ɫView)

// ����
public:
	C��ɫDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��ɫView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ɫView.cpp �еĵ��԰汾
inline C��ɫDoc* C��ɫView::GetDocument() const
   { return reinterpret_cast<C��ɫDoc*>(m_pDocument); }
#endif

