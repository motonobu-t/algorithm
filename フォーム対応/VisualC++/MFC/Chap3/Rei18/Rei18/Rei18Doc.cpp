// Rei18Doc.cpp : CRei18Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei18.h"

#include "Rei18Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei18Doc

IMPLEMENT_DYNCREATE(CRei18Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei18Doc, CDocument)
END_MESSAGE_MAP()


// CRei18Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei18Doc::CRei18Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei18Doc::~CRei18Doc()
{
}

BOOL CRei18Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei18Doc �V���A����

void CRei18Doc::Serialize(CArchive& ar)
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


// CRei18Doc �f�f

#ifdef _DEBUG
void CRei18Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei18Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei18Doc �R�}���h
