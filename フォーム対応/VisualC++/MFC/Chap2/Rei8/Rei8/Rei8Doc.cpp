// Rei8Doc.cpp : CRei8Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei8.h"

#include "Rei8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei8Doc

IMPLEMENT_DYNCREATE(CRei8Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei8Doc, CDocument)
END_MESSAGE_MAP()


// CRei8Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei8Doc::CRei8Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei8Doc::~CRei8Doc()
{
}

BOOL CRei8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei8Doc �V���A����

void CRei8Doc::Serialize(CArchive& ar)
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


// CRei8Doc �f�f

#ifdef _DEBUG
void CRei8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei8Doc �R�}���h
