// Rei57Doc.cpp : CRei57Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei57.h"

#include "Rei57Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei57Doc

IMPLEMENT_DYNCREATE(CRei57Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei57Doc, CDocument)
END_MESSAGE_MAP()


// CRei57Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei57Doc::CRei57Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei57Doc::~CRei57Doc()
{
}

BOOL CRei57Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei57Doc �V���A����

void CRei57Doc::Serialize(CArchive& ar)
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


// CRei57Doc �f�f

#ifdef _DEBUG
void CRei57Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei57Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei57Doc �R�}���h
