
// DB2View.h : CDB2View ��Ľӿ�
//

#pragma once

class CDB2Set;

class CDB2View : public CRecordView
{
protected: // �������л�����
	CDB2View();
	DECLARE_DYNCREATE(CDB2View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB2_FORM };
#endif
	CDB2Set* m_pSet;
	CString filename,path;


// ����
public:
	CDB2Doc* GetDocument() const;

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
	virtual ~CDB2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

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
	void CDB2View::draw_pic(CString file);
		afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // DB2View.cpp �еĵ��԰汾
inline CDB2Doc* CDB2View::GetDocument() const
   { return reinterpret_cast<CDB2Doc*>(m_pDocument); }
#endif

