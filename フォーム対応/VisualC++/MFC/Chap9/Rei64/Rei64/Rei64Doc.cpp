// Rei64Doc.cpp : CRei64Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei64.h"

#include "Rei64Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei64Doc

IMPLEMENT_DYNCREATE(CRei64Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei64Doc, CDocument)
END_MESSAGE_MAP()


// CRei64Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei64Doc::CRei64Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei64Doc::~CRei64Doc()
{
}

BOOL CRei64Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei64Doc �V���A����

void CRei64Doc::Serialize(CArchive& ar)
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


// CRei64Doc �f�f

#ifdef _DEBUG
void CRei64Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei64Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei64Doc �R�}���h
