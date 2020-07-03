
// DB001Set.cpp : CDB001Set ���ʵ��
//

#include "stdafx.h"
#include "DB001.h"
#include "DB001Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB001Set ʵ��

// ���������� 2020��5��26��, 12:31

IMPLEMENT_DYNAMIC(CDB001Set, CRecordset)

CDB001Set::CDB001Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	m_nFields = 1;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[��Ƭ�ļ���]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CDB001Set ���

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

