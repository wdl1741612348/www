
// exp14-2-2View.h : Cexp1422View ��Ľӿ�
//

#pragma once


class Cexp1422View : public CView
{
protected: // �������л�����
	Cexp1422View();
	DECLARE_DYNCREATE(Cexp1422View)

// ����
public:
	Cexp1422Doc* GetDocument() const;

// ����
public:
	CRect cr;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp1422View();
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
};

#ifndef _DEBUG  // exp14-2-2View.cpp �еĵ��԰汾
inline Cexp1422Doc* Cexp1422View::GetDocument() const
   { return reinterpret_cast<Cexp1422Doc*>(m_pDocument); }
#endif

