// Rei55Doc.cpp : CRei55Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei55.h"

#include "Rei55Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei55Doc

IMPLEMENT_DYNCREATE(CRei55Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei55Doc, CDocument)
END_MESSAGE_MAP()


// CRei55Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei55Doc::CRei55Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei55Doc::~CRei55Doc()
{
}

BOOL CRei55Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei55Doc �V���A����

void CRei55Doc::Serialize(CArchive& ar)
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


// CRei55Doc �f�f

#ifdef _DEBUG
void CRei55Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei55Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei55Doc �R�}���h
