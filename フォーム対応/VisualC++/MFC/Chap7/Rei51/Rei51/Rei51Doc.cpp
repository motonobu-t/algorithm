// Rei51Doc.cpp : CRei51Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei51.h"

#include "Rei51Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei51Doc

IMPLEMENT_DYNCREATE(CRei51Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei51Doc, CDocument)
END_MESSAGE_MAP()


// CRei51Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei51Doc::CRei51Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei51Doc::~CRei51Doc()
{
}

BOOL CRei51Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei51Doc �V���A����

void CRei51Doc::Serialize(CArchive& ar)
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


// CRei51Doc �f�f

#ifdef _DEBUG
void CRei51Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei51Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei51Doc �R�}���h
