
// DB001View.h : CDB001View ��Ľӿ�
//

#pragma once

class CDB001Set;

class CDB001View : public CRecordView
{
protected: // �������л�����
	CDB001View();
	DECLARE_DYNCREATE(CDB001View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB001_FORM };
#endif
	CDB001Set* m_pSet;
	CString path;
// ����
public:
	CDB001Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CDB001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CDB001View::draw_pic(CString file);
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
//	afx_msg void OnPaint();
};

#ifndef _DEBUG  // DB001View.cpp �еĵ��԰汾
inline CDB001Doc* CDB001View::GetDocument() const
   { return reinterpret_cast<CDB001Doc*>(m_pDocument); }
#endif

