// Rei38Doc.cpp : CRei38Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei38.h"

#include "Rei38Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei38Doc

IMPLEMENT_DYNCREATE(CRei38Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei38Doc, CDocument)
END_MESSAGE_MAP()


// CRei38Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei38Doc::CRei38Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei38Doc::~CRei38Doc()
{
}

BOOL CRei38Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei38Doc �V���A����

void CRei38Doc::Serialize(CArchive& ar)
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


// CRei38Doc �f�f

#ifdef _DEBUG
void CRei38Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei38Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei38Doc �R�}���h
