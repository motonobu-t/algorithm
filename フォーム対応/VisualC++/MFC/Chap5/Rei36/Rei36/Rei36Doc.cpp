// Rei36Doc.cpp : CRei36Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei36.h"

#include "Rei36Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei36Doc

IMPLEMENT_DYNCREATE(CRei36Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei36Doc, CDocument)
END_MESSAGE_MAP()


// CRei36Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei36Doc::CRei36Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei36Doc::~CRei36Doc()
{
}

BOOL CRei36Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei36Doc �V���A����

void CRei36Doc::Serialize(CArchive& ar)
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


// CRei36Doc �f�f

#ifdef _DEBUG
void CRei36Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei36Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei36Doc �R�}���h
