
// DB0505-3Doc.h : CDB05053Doc 类的接口
//


#pragma once
#include "DB0505-3Set.h"


class CDB05053Doc : public CDocument
{
protected: // 仅从序列化创建
	CDB05053Doc();
	DECLARE_DYNCREATE(CDB05053Doc)

// 特性
public:
	CDB05053Set m_DB05053Set;

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CDB05053Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
