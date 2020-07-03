
// DB002View.h : CDB002View ��Ľӿ�
//

#pragma once

class CDB002Set;

class CDB002View : public CRecordView
{
protected: // �������л�����
	CDB002View();
	DECLARE_DYNCREATE(CDB002View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB002_FORM };
#endif
	CDB002Set* m_pSet;
	CString path;
// ����
public:
	CDB002Doc* GetDocument() const;

// ����
public:
	int sx, sy, w, h;
	CString filename, f;
	CRect cr;
	CImage img;
// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB002View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CDB002View::draw_pic(CString file);
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString s;
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // DB002View.cpp �еĵ��԰汾
inline CDB002Doc* CDB002View::GetDocument() const
   { return reinterpret_cast<CDB002Doc*>(m_pDocument); }
#endif

