// Rei53Doc.cpp : CRei53Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei53.h"

#include "Rei53Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei53Doc

IMPLEMENT_DYNCREATE(CRei53Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei53Doc, CDocument)
END_MESSAGE_MAP()


// CRei53Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei53Doc::CRei53Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei53Doc::~CRei53Doc()
{
}

BOOL CRei53Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei53Doc �V���A����

void CRei53Doc::Serialize(CArchive& ar)
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


// CRei53Doc �f�f

#ifdef _DEBUG
void CRei53Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei53Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei53Doc �R�}���h
