// Rei21Doc.cpp : CRei21Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei21.h"

#include "Rei21Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei21Doc

IMPLEMENT_DYNCREATE(CRei21Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei21Doc, CDocument)
END_MESSAGE_MAP()


// CRei21Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei21Doc::CRei21Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei21Doc::~CRei21Doc()
{
}

BOOL CRei21Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei21Doc �V���A����

void CRei21Doc::Serialize(CArchive& ar)
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


// CRei21Doc �f�f

#ifdef _DEBUG
void CRei21Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei21Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei21Doc �R�}���h
