
// exp13-2View.h : Cexp132View ��Ľӿ�
//

#pragma once


class Cexp132View : public CView
{
protected: // �������л�����
	Cexp132View();
	DECLARE_DYNCREATE(Cexp132View)

// ����
public:
	Cexp132Doc* GetDocument() const;

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
	virtual ~Cexp132View();
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
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // exp13-2View.cpp �еĵ��԰汾
inline Cexp132Doc* Cexp132View::GetDocument() const
   { return reinterpret_cast<Cexp132Doc*>(m_pDocument); }
#endif

