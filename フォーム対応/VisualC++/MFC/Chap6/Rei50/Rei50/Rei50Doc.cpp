// Rei50Doc.cpp : CRei50Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei50.h"

#include "Rei50Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei50Doc

IMPLEMENT_DYNCREATE(CRei50Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei50Doc, CDocument)
END_MESSAGE_MAP()


// CRei50Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei50Doc::CRei50Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei50Doc::~CRei50Doc()
{
}

BOOL CRei50Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei50Doc �V���A����

void CRei50Doc::Serialize(CArchive& ar)
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


// CRei50Doc �f�f

#ifdef _DEBUG
void CRei50Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei50Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei50Doc �R�}���h
