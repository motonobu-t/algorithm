// Rei62Doc.cpp : CRei62Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei62.h"

#include "Rei62Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei62Doc

IMPLEMENT_DYNCREATE(CRei62Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei62Doc, CDocument)
END_MESSAGE_MAP()


// CRei62Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei62Doc::CRei62Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei62Doc::~CRei62Doc()
{
}

BOOL CRei62Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei62Doc �V���A����

void CRei62Doc::Serialize(CArchive& ar)
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


// CRei62Doc �f�f

#ifdef _DEBUG
void CRei62Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei62Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei62Doc �R�}���h
