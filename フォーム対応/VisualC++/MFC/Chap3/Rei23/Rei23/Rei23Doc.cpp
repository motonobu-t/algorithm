// Rei23Doc.cpp : CRei23Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei23.h"

#include "Rei23Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei23Doc

IMPLEMENT_DYNCREATE(CRei23Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei23Doc, CDocument)
END_MESSAGE_MAP()


// CRei23Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei23Doc::CRei23Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei23Doc::~CRei23Doc()
{
}

BOOL CRei23Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei23Doc �V���A����

void CRei23Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}


// CRei23Doc �f�f

#ifdef _DEBUG
void CRei23Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei23Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei23Doc �R�}���h
