
// MFC01View.h : CMFC01View ��Ľӿ�
//

#pragma once


class CMFC01View : public CView
{
protected: // �������л�����
	CMFC01View();
	DECLARE_DYNCREATE(CMFC01View)

// ����
public:
	CMFC01Doc* GetDocument() const;

// ����
public:
	int N,K;
	CArray<CRect, CRect> cr;
	bool set;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMFC01View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // MFC01View.cpp �еĵ��԰汾
inline CMFC01Doc* CMFC01View::GetDocument() const
   { return reinterpret_cast<CMFC01Doc*>(m_pDocument); }
#endif

