// Rei12Doc.cpp : CRei12Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei12.h"

#include "Rei12Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei12Doc

IMPLEMENT_DYNCREATE(CRei12Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei12Doc, CDocument)
END_MESSAGE_MAP()


// CRei12Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei12Doc::CRei12Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei12Doc::~CRei12Doc()
{
}

BOOL CRei12Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei12Doc �V���A����

void CRei12Doc::Serialize(CArchive& ar)
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


// CRei12Doc �f�f

#ifdef _DEBUG
void CRei12Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei12Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei12Doc �R�}���h
