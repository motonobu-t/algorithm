// Rei35Doc.cpp : CRei35Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei35.h"

#include "Rei35Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei35Doc

IMPLEMENT_DYNCREATE(CRei35Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei35Doc, CDocument)
END_MESSAGE_MAP()


// CRei35Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei35Doc::CRei35Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei35Doc::~CRei35Doc()
{
}

BOOL CRei35Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei35Doc �V���A����

void CRei35Doc::Serialize(CArchive& ar)
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


// CRei35Doc �f�f

#ifdef _DEBUG
void CRei35Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei35Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei35Doc �R�}���h
