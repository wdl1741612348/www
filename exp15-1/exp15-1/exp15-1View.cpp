
// exp15-1View.cpp : Cexp151View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "exp15-1.h"
#endif

#include "exp15-1Doc.h"
#include "exp15-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include<fstream>
using namespace std;
// Cexp151View

IMPLEMENT_DYNCREATE(Cexp151View, CView)

BEGIN_MESSAGE_MAP(Cexp151View, CView)
	ON_COMMAND(ID_FILE_OPEN, &Cexp151View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &Cexp151View::OnFileSave)
END_MESSAGE_MAP()

// Cexp151View 构造/析构

Cexp151View::Cexp151View()
{
	// TODO: 在此处添加构造代码

}

Cexp151View::~Cexp151View()
{
}

BOOL Cexp151View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cexp151View 绘制

void Cexp151View::OnDraw(CDC* /*pDC*/)
{
	Cexp151Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// Cexp151View 诊断

#ifdef _DEBUG
void Cexp151View::AssertValid() const
{
	CView::AssertValid();
}

void Cexp151View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cexp151Doc* Cexp151View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cexp151Doc)));
	return (Cexp151Doc*)m_pDocument;
}
#endif //_DEBUG


// Cexp151View 消息处理程序


void Cexp151View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(true);  
	int r = cfd.DoModal();  
	CClientDC dc(this);
	if (r == IDOK)
	{
		
		filename = cfd.GetPathName(); //路径名

	}
}


void Cexp151View::OnFileSave()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog cfd(false);
	int r = cfd.DoModal();
	if (r == IDOK)
	{
		ofstream ofs(cfd.GetPathName());
		ofs << CT2A(filename.GetString())<<endl;
	}
}
