
// exp13-3View.h : Cexp133View ��Ľӿ�
//

#pragma once


class Cexp133View : public CView
{
protected: // �������л�����
	Cexp133View();
	DECLARE_DYNCREATE(Cexp133View)

// ����
public:
	Cexp133Doc* GetDocument() const;

// ����
public:
	CString s;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp133View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopout();
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp13-3View.cpp �еĵ��԰汾
inline Cexp133Doc* Cexp133View::GetDocument() const
   { return reinterpret_cast<Cexp133Doc*>(m_pDocument); }
#endif

