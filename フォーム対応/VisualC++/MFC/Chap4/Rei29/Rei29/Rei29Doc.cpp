// Rei29Doc.cpp : CRei29Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei29.h"

#include "Rei29Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei29Doc

IMPLEMENT_DYNCREATE(CRei29Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei29Doc, CDocument)
END_MESSAGE_MAP()


// CRei29Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei29Doc::CRei29Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei29Doc::~CRei29Doc()
{
}

BOOL CRei29Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei29Doc �V���A����

void CRei29Doc::Serialize(CArchive& ar)
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


// CRei29Doc �f�f

#ifdef _DEBUG
void CRei29Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei29Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei29Doc �R�}���h
