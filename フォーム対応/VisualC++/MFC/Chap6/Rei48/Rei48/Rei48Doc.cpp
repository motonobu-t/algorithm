// Rei48Doc.cpp : CRei48Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei48.h"

#include "Rei48Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei48Doc

IMPLEMENT_DYNCREATE(CRei48Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei48Doc, CDocument)
END_MESSAGE_MAP()


// CRei48Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei48Doc::CRei48Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei48Doc::~CRei48Doc()
{
}

BOOL CRei48Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei48Doc �V���A����

void CRei48Doc::Serialize(CArchive& ar)
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


// CRei48Doc �f�f

#ifdef _DEBUG
void CRei48Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei48Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei48Doc �R�}���h
