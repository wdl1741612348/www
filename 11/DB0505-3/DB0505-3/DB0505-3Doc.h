
// DB0505-3Doc.h : CDB05053Doc ��Ľӿ�
//


#pragma once
#include "DB0505-3Set.h"


class CDB05053Doc : public CDocument
{
protected: // �������л�����
	CDB05053Doc();
	DECLARE_DYNCREATE(CDB05053Doc)

// ����
public:
	CDB05053Set m_DB05053Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CDB05053Doc();
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
