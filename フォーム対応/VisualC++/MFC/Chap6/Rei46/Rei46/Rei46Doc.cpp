// Rei46Doc.cpp : CRei46Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei46.h"

#include "Rei46Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei46Doc

IMPLEMENT_DYNCREATE(CRei46Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei46Doc, CDocument)
END_MESSAGE_MAP()


// CRei46Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei46Doc::CRei46Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei46Doc::~CRei46Doc()
{
}

BOOL CRei46Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei46Doc �V���A����

void CRei46Doc::Serialize(CArchive& ar)
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


// CRei46Doc �f�f

#ifdef _DEBUG
void CRei46Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei46Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei46Doc �R�}���h
