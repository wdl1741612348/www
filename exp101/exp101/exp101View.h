
// exp101View.h : Cexp101View ��Ľӿ�
//

#pragma once


class Cexp101View : public CView
{
protected: // �������л�����
	Cexp101View();
	DECLARE_DYNCREATE(Cexp101View)

// ����
public:
	Cexp101Doc* GetDocument() const;

// ����
public:
	CString s;
	int a, b;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp101View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // exp101View.cpp �еĵ��԰汾
inline Cexp101Doc* Cexp101View::GetDocument() const
   { return reinterpret_cast<Cexp101Doc*>(m_pDocument); }
#endif

