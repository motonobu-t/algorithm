// Rei19Doc.cpp : CRei19Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei19.h"

#include "Rei19Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei19Doc

IMPLEMENT_DYNCREATE(CRei19Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei19Doc, CDocument)
END_MESSAGE_MAP()


// CRei19Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei19Doc::CRei19Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei19Doc::~CRei19Doc()
{
}

BOOL CRei19Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei19Doc �V���A����

void CRei19Doc::Serialize(CArchive& ar)
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


// CRei19Doc �f�f

#ifdef _DEBUG
void CRei19Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei19Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei19Doc �R�}���h
