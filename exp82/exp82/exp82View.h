
// exp82View.h : Cexp82View ��Ľӿ�
//

#pragma once


class Cexp82View : public CView
{
protected: // �������л�����
	Cexp82View();
	DECLARE_DYNCREATE(Cexp82View)

// ����
public:
	Cexp82Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;       //λͼ����
	int m_nWidth;           //�洢λͼ������ݳ�Ա
	int m_nHeight;
// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~Cexp82View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // exp82View.cpp �еĵ��԰汾
inline Cexp82Doc* Cexp82View::GetDocument() const
   { return reinterpret_cast<Cexp82Doc*>(m_pDocument); }
#endif

