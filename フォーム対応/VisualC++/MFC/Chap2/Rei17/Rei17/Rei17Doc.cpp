// Rei17Doc.cpp : CRei17Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei17.h"

#include "Rei17Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei17Doc

IMPLEMENT_DYNCREATE(CRei17Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei17Doc, CDocument)
END_MESSAGE_MAP()


// CRei17Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei17Doc::CRei17Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei17Doc::~CRei17Doc()
{
}

BOOL CRei17Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei17Doc �V���A����

void CRei17Doc::Serialize(CArchive& ar)
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


// CRei17Doc �f�f

#ifdef _DEBUG
void CRei17Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei17Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei17Doc �R�}���h
