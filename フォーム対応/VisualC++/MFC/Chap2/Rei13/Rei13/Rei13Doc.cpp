// Rei13Doc.cpp : CRei13Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei13.h"

#include "Rei13Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei13Doc

IMPLEMENT_DYNCREATE(CRei13Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei13Doc, CDocument)
END_MESSAGE_MAP()


// CRei13Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei13Doc::CRei13Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei13Doc::~CRei13Doc()
{
}

BOOL CRei13Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei13Doc �V���A����

void CRei13Doc::Serialize(CArchive& ar)
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


// CRei13Doc �f�f

#ifdef _DEBUG
void CRei13Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei13Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei13Doc �R�}���h
