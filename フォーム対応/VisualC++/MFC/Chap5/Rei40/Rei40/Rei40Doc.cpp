// Rei40Doc.cpp : CRei40Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei40.h"

#include "Rei40Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei40Doc

IMPLEMENT_DYNCREATE(CRei40Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei40Doc, CDocument)
END_MESSAGE_MAP()


// CRei40Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei40Doc::CRei40Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei40Doc::~CRei40Doc()
{
}

BOOL CRei40Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei40Doc �V���A����

void CRei40Doc::Serialize(CArchive& ar)
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


// CRei40Doc �f�f

#ifdef _DEBUG
void CRei40Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei40Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei40Doc �R�}���h
