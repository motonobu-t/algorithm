// Rei61Doc.cpp : CRei61Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei61.h"

#include "Rei61Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei61Doc

IMPLEMENT_DYNCREATE(CRei61Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei61Doc, CDocument)
END_MESSAGE_MAP()


// CRei61Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei61Doc::CRei61Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei61Doc::~CRei61Doc()
{
}

BOOL CRei61Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei61Doc �V���A����

void CRei61Doc::Serialize(CArchive& ar)
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


// CRei61Doc �f�f

#ifdef _DEBUG
void CRei61Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei61Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei61Doc �R�}���h
