// Rei56Doc.cpp : CRei56Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei56.h"

#include "Rei56Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei56Doc

IMPLEMENT_DYNCREATE(CRei56Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei56Doc, CDocument)
END_MESSAGE_MAP()


// CRei56Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei56Doc::CRei56Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei56Doc::~CRei56Doc()
{
}

BOOL CRei56Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei56Doc �V���A����

void CRei56Doc::Serialize(CArchive& ar)
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


// CRei56Doc �f�f

#ifdef _DEBUG
void CRei56Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei56Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei56Doc �R�}���h
