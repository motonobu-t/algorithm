// Rei66Doc.cpp : CRei66Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei66.h"

#include "Rei66Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66Doc

IMPLEMENT_DYNCREATE(CRei66Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei66Doc, CDocument)
END_MESSAGE_MAP()


// CRei66Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei66Doc::CRei66Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei66Doc::~CRei66Doc()
{
}

BOOL CRei66Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei66Doc �V���A����

void CRei66Doc::Serialize(CArchive& ar)
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


// CRei66Doc �f�f

#ifdef _DEBUG
void CRei66Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei66Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei66Doc �R�}���h
