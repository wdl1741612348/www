
// exp12-4View.h : Cexp124View ��Ľӿ�
//

#pragma once


class Cexp124View : public CView
{
protected: // �������л�����
	Cexp124View();
	DECLARE_DYNCREATE(Cexp124View)

// ����
public:
	Cexp124Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp124View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPopup();
};

#ifndef _DEBUG  // exp12-4View.cpp �еĵ��԰汾
inline Cexp124Doc* Cexp124View::GetDocument() const
   { return reinterpret_cast<Cexp124Doc*>(m_pDocument); }
#endif

