
// exp22View.h : Cexp22View ��Ľӿ�
//

#pragma once


class Cexp22View : public CView
{
protected: // �������л�����
	Cexp22View();
	DECLARE_DYNCREATE(Cexp22View)

// ����
public:
	Cexp22Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp22View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp22View.cpp �еĵ��԰汾
inline Cexp22Doc* Cexp22View::GetDocument() const
   { return reinterpret_cast<Cexp22Doc*>(m_pDocument); }
#endif

