// Rei32Doc.cpp : CRei32Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei32.h"

#include "Rei32Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei32Doc

IMPLEMENT_DYNCREATE(CRei32Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei32Doc, CDocument)
END_MESSAGE_MAP()


// CRei32Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei32Doc::CRei32Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei32Doc::~CRei32Doc()
{
}

BOOL CRei32Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei32Doc �V���A����

void CRei32Doc::Serialize(CArchive& ar)
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


// CRei32Doc �f�f

#ifdef _DEBUG
void CRei32Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei32Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei32Doc �R�}���h
