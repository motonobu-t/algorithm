// Rei33Doc.cpp : CRei33Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei33.h"

#include "Rei33Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei33Doc

IMPLEMENT_DYNCREATE(CRei33Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei33Doc, CDocument)
END_MESSAGE_MAP()


// CRei33Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei33Doc::CRei33Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei33Doc::~CRei33Doc()
{
}

BOOL CRei33Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei33Doc �V���A����

void CRei33Doc::Serialize(CArchive& ar)
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


// CRei33Doc �f�f

#ifdef _DEBUG
void CRei33Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei33Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei33Doc �R�}���h
