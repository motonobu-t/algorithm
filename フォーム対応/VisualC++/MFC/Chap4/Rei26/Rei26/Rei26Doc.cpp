// Rei26Doc.cpp : CRei26Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei26.h"

#include "Rei26Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei26Doc

IMPLEMENT_DYNCREATE(CRei26Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei26Doc, CDocument)
END_MESSAGE_MAP()


// CRei26Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei26Doc::CRei26Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei26Doc::~CRei26Doc()
{
}

BOOL CRei26Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei26Doc �V���A����

void CRei26Doc::Serialize(CArchive& ar)
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


// CRei26Doc �f�f

#ifdef _DEBUG
void CRei26Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei26Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei26Doc �R�}���h
