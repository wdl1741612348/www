
// ecp72View.h : Cecp72View ��Ľӿ�
//

#pragma once


class Cecp72View : public CView
{
protected: // �������л�����
	Cecp72View();
	DECLARE_DYNCREATE(Cecp72View)

// ����
public:
	Cecp72Doc* GetDocument() const;

// ����
public:
	bool set;
	int N;
	int color,red,green,blue;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cecp72View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawcircle();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // ecp72View.cpp �еĵ��԰汾
inline Cecp72Doc* Cecp72View::GetDocument() const
   { return reinterpret_cast<Cecp72Doc*>(m_pDocument); }
#endif

