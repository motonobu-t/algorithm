// Rei27Doc.cpp : CRei27Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei27.h"

#include "Rei27Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei27Doc

IMPLEMENT_DYNCREATE(CRei27Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei27Doc, CDocument)
END_MESSAGE_MAP()


// CRei27Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei27Doc::CRei27Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei27Doc::~CRei27Doc()
{
}

BOOL CRei27Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei27Doc �V���A����

void CRei27Doc::Serialize(CArchive& ar)
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


// CRei27Doc �f�f

#ifdef _DEBUG
void CRei27Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei27Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei27Doc �R�}���h
