
// DB0505Set.cpp : CDB0505Set ���ʵ��
//

#include "stdafx.h"
#include "DB0505.h"
#include "DB0505Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB0505Set ʵ��

// ���������� 2020��5��19��, 17:08

IMPLEMENT_DYNAMIC(CDB0505Set, CRecordset)

CDB0505Set::CDB0505Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	column1 = L"";
	column2 = 0.0;
	column3 = 0.0;
	column4 = L"";
	m_nFields = 4;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB0505Set::GetDefaultConnect()
{
	return _T("DSN=����Դ_ѧ����Ϣ2;DBQ=D:\\\x6570\x636e\x6e90\\\x5b66\x751f\x4fe1\x606f\x8868\x4e8c.xls;DefaultDir=D:\\\x6570\x636e\x6e90;DriverId=790;FIL=excel 8.0;MaxBufferSize=2048;PageTimeout=5;");
}

CString CDB0505Set::GetDefaultSQL()
{
	return _T("[Sheet1$]");
}

void CDB0505Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Double(pFX, _T("[ѧ��]"), column2);
	RFX_Double(pFX, _T("[����]"), column3);
	RFX_Text(pFX, _T("[ѧ��������Ƭ��ȫ·��]"), column4);

}
/////////////////////////////////////////////////////////////////////////////
// CDB0505Set ���

#ifdef _DEBUG
void CDB0505Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB0505Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

