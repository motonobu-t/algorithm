// Rei60Doc.cpp : CRei60Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei60.h"

#include "Rei60Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei60Doc

IMPLEMENT_DYNCREATE(CRei60Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei60Doc, CDocument)
END_MESSAGE_MAP()


// CRei60Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei60Doc::CRei60Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei60Doc::~CRei60Doc()
{
}

BOOL CRei60Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei60Doc �V���A����

void CRei60Doc::Serialize(CArchive& ar)
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


// CRei60Doc �f�f

#ifdef _DEBUG
void CRei60Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei60Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei60Doc �R�}���h
