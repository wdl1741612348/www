
// exp91View.h : Cexp91View ��Ľӿ�
//

#pragma once


class Cexp91View : public CView
{
protected: // �������л�����
	Cexp91View();
	DECLARE_DYNCREATE(Cexp91View)

// ����
public:
	Cexp91Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp91View();
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
};

#ifndef _DEBUG  // exp91View.cpp �еĵ��԰汾
inline Cexp91Doc* Cexp91View::GetDocument() const
   { return reinterpret_cast<Cexp91Doc*>(m_pDocument); }
#endif

