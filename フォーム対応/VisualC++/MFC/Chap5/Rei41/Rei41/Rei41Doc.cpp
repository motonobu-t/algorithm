// Rei41Doc.cpp : CRei41Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei41.h"

#include "Rei41Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei41Doc

IMPLEMENT_DYNCREATE(CRei41Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei41Doc, CDocument)
END_MESSAGE_MAP()


// CRei41Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei41Doc::CRei41Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei41Doc::~CRei41Doc()
{
}

BOOL CRei41Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei41Doc �V���A����

void CRei41Doc::Serialize(CArchive& ar)
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


// CRei41Doc �f�f

#ifdef _DEBUG
void CRei41Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei41Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei41Doc �R�}���h
