// Rei31Doc.cpp : CRei31Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei31.h"

#include "Rei31Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei31Doc

IMPLEMENT_DYNCREATE(CRei31Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei31Doc, CDocument)
END_MESSAGE_MAP()


// CRei31Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei31Doc::CRei31Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei31Doc::~CRei31Doc()
{
}

BOOL CRei31Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei31Doc �V���A����

void CRei31Doc::Serialize(CArchive& ar)
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


// CRei31Doc �f�f

#ifdef _DEBUG
void CRei31Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei31Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei31Doc �R�}���h
