
// exp21View.h : Cexp21View ��Ľӿ�
//

#pragma once


class Cexp21View : public CView
{
protected: // �������л�����
	Cexp21View();
	DECLARE_DYNCREATE(Cexp21View)

// ����
public:
	Cexp21Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp21View.cpp �еĵ��԰汾
inline Cexp21Doc* Cexp21View::GetDocument() const
   { return reinterpret_cast<Cexp21Doc*>(m_pDocument); }
#endif

