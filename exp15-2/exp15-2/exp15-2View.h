
// exp15-2View.h : Cexp152View ��Ľӿ�
//

#pragma once


class Cexp152View : public CView
{
protected: // �������л�����
	Cexp152View();
	DECLARE_DYNCREATE(Cexp152View)

// ����
public:
	Cexp152Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp152View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void foo(CImage &img, int &sx, int &sy, int &w, int &h);
};

#ifndef _DEBUG  // exp15-2View.cpp �еĵ��԰汾
inline Cexp152Doc* Cexp152View::GetDocument() const
   { return reinterpret_cast<Cexp152Doc*>(m_pDocument); }
#endif

