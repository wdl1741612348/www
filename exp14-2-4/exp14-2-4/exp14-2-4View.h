
// exp14-2-4View.h : Cexp1424View ��Ľӿ�
//

#pragma once


class Cexp1424View : public CView
{
protected: // �������л�����
	Cexp1424View();
	DECLARE_DYNCREATE(Cexp1424View)

// ����
public:
	Cexp1424Doc* GetDocument() const;

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
	virtual ~Cexp1424View();
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

#ifndef _DEBUG  // exp14-2-4View.cpp �еĵ��԰汾
inline Cexp1424Doc* Cexp1424View::GetDocument() const
   { return reinterpret_cast<Cexp1424Doc*>(m_pDocument); }
#endif

