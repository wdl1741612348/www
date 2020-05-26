
// DB0505-3Set.cpp : CDB05053Set 类的实现
//

#include "stdafx.h"
#include "DB0505-3.h"
#include "DB0505-3Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB05053Set 实现

// 代码生成在 2020年5月19日, 18:18

IMPLEMENT_DYNAMIC(CDB05053Set, CRecordset)

CDB05053Set::CDB05053Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CDB05053Set::GetDefaultConnect()
{
	return _T("DSN=数据源_学生信息2;DBQ=D:\\\x6570\x636e\x6e90\\\x5b66\x751f\x4fe1\x606f\x8868\x4e8c.xls;DefaultDir=D:\\\x6570\x636e\x6e90;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CDB05053Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CDB05053Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Double(pFX, _T("[学号]"), column2);
	RFX_Double(pFX, _T("[年龄]"), column3);
	RFX_Text(pFX, _T("[学生本人相片的全路径]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CDB05053Set 诊断

#ifdef _DEBUG
void CDB05053Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB05053Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

