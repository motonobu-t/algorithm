// Rei7Doc.cpp : CRei7Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei7.h"

#include "Rei7Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei7Doc

IMPLEMENT_DYNCREATE(CRei7Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei7Doc, CDocument)
END_MESSAGE_MAP()


// CRei7Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei7Doc::CRei7Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei7Doc::~CRei7Doc()
{
}

BOOL CRei7Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei7Doc �V���A����

void CRei7Doc::Serialize(CArchive& ar)
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


// CRei7Doc �f�f

#ifdef _DEBUG
void CRei7Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei7Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei7Doc �R�}���h
