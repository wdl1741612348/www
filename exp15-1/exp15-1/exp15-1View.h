
// exp15-1View.h : Cexp151View ��Ľӿ�
//

#pragma once


class Cexp151View : public CView
{
protected: // �������л�����
	Cexp151View();
	DECLARE_DYNCREATE(Cexp151View)

// ����
public:
	Cexp151Doc* GetDocument() const;

// ����
public:
	CString filename;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp151View();
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
	afx_msg void OnFileSave();
};

#ifndef _DEBUG  // exp15-1View.cpp �еĵ��԰汾
inline Cexp151Doc* Cexp151View::GetDocument() const
   { return reinterpret_cast<Cexp151Doc*>(m_pDocument); }
#endif

