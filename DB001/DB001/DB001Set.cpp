
// DB001Set.cpp : CDB001Set 类的实现
//

#include "stdafx.h"
#include "DB001.h"
#include "DB001Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB001Set 实现

// 代码生成在 2020年5月26日, 12:31

IMPLEMENT_DYNAMIC(CDB001Set, CRecordset)

CDB001Set::CDB001Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CDB001Set::GetDefaultConnect()
{
	return _T("DSN=\x6570\x636e\x6e90_\x76f8\x7247\x6587\x4ef6;DBQ=D:\\\x6570\x636e\x6e90\\\x76f8\x7247\x6587\x4ef6\x5e93.xls;DefaultDir=D:\\\x6570\x636e\x6e90;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CDB001Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CDB001Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[相片文件名]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CDB001Set 诊断

#ifdef _DEBUG
void CDB001Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB001Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

