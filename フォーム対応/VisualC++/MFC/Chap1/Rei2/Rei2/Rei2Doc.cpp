// Rei2Doc.cpp : CRei2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei2.h"

#include "Rei2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei2Doc

IMPLEMENT_DYNCREATE(CRei2Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei2Doc, CDocument)
END_MESSAGE_MAP()


// CRei2Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei2Doc::CRei2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei2Doc::~CRei2Doc()
{
}

BOOL CRei2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei2Doc �V���A����

void CRei2Doc::Serialize(CArchive& ar)
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


// CRei2Doc �f�f

#ifdef _DEBUG
void CRei2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei2Doc �R�}���h
