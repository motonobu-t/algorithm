// Rei47Doc.cpp : CRei47Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei47.h"

#include "Rei47Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei47Doc

IMPLEMENT_DYNCREATE(CRei47Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei47Doc, CDocument)
END_MESSAGE_MAP()


// CRei47Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei47Doc::CRei47Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei47Doc::~CRei47Doc()
{
}

BOOL CRei47Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei47Doc �V���A����

void CRei47Doc::Serialize(CArchive& ar)
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


// CRei47Doc �f�f

#ifdef _DEBUG
void CRei47Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei47Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei47Doc �R�}���h
