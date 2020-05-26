
// DB0505-3View.h : CDB05053View ��Ľӿ�
//

#pragma once

class CDB05053Set;

class CDB05053View : public CRecordView
{
protected: // �������л�����
	CDB05053View();
	DECLARE_DYNCREATE(CDB05053View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DB05053_FORM };
#endif
	CDB05053Set* m_pSet;

// ����
public:
	CDB05053Doc* GetDocument() const;

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
	virtual ~CDB05053View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	void CDB05053View::foo(CImage &img, int &sx, int &sy, int &w, int &h);
protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	double number;
	double age;
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // DB0505-3View.cpp �еĵ��԰汾
inline CDB05053Doc* CDB05053View::GetDocument() const
   { return reinterpret_cast<CDB05053Doc*>(m_pDocument); }
#endif

