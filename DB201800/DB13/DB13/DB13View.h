
// DB13View.h : CDB13View ��Ľӿ�
//

#pragma once

class CDB13Set;

class CDB13View : public CRecordView
{
protected: // �������л�����
	CDB13View();
	DECLARE_DYNCREATE(CDB13View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB13_FORM };
#endif
	CDB13Set* m_pSet;

// ����
public:
	CDB13Doc* GetDocument() const;

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
	virtual ~CDB13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString ss;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // DB13View.cpp �еĵ��԰汾
inline CDB13Doc* CDB13View::GetDocument() const
   { return reinterpret_cast<CDB13Doc*>(m_pDocument); }
#endif

