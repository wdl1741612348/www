
// DB13Set.cpp : CDB13Set ���ʵ��
//

#include "stdafx.h"
#include "DB13.h"
#include "DB13Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDB13Set ʵ��

// ���������� 2020��7��3��, 23:05

IMPLEMENT_DYNAMIC(CDB13Set, CRecordset)

CDB13Set::CDB13Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	m_nFields = 2;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CDB13Set::GetDefaultConnect()
{
	return _T("DSN=����Դ_��Ƭ13;DBQ=D:\\\x8868.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString CDB13Set::GetDefaultSQL()
{
	return _T("[��1]");
}

void CDB13Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[ͼƬ����]"), column1);

}
/////////////////////////////////////////////////////////////////////////////
// CDB13Set ���

#ifdef _DEBUG
void CDB13Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void CDB13Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

