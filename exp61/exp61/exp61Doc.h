
// exp61Doc.h : Cexp61Doc ��Ľӿ�
//


#pragma once


class Cexp61Doc : public CDocument
{
protected: // �������л�����
	Cexp61Doc();
	DECLARE_DYNCREATE(Cexp61Doc)

// ����
public:

// ����
public:
	CPoint a_point, b_point;
	int i;
	CString s1, s2;
// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cexp61Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
