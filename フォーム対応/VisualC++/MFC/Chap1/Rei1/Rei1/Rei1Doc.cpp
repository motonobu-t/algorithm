// Rei1Doc.cpp : CRei1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei1.h"

#include "Rei1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei1Doc

IMPLEMENT_DYNCREATE(CRei1Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei1Doc, CDocument)
END_MESSAGE_MAP()


// CRei1Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei1Doc::CRei1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei1Doc::~CRei1Doc()
{
}

BOOL CRei1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei1Doc �V���A����

void CRei1Doc::Serialize(CArchive& ar)
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


// CRei1Doc �f�f

#ifdef _DEBUG
void CRei1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei1Doc �R�}���h
