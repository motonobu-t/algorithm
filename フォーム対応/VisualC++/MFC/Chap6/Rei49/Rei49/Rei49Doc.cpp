// Rei49Doc.cpp : CRei49Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei49.h"

#include "Rei49Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei49Doc

IMPLEMENT_DYNCREATE(CRei49Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei49Doc, CDocument)
END_MESSAGE_MAP()


// CRei49Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei49Doc::CRei49Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei49Doc::~CRei49Doc()
{
}

BOOL CRei49Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei49Doc �V���A����

void CRei49Doc::Serialize(CArchive& ar)
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


// CRei49Doc �f�f

#ifdef _DEBUG
void CRei49Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei49Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei49Doc �R�}���h
