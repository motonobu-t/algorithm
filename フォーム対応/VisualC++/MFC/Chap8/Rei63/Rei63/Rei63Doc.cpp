// Rei63Doc.cpp : CRei63Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei63.h"

#include "Rei63Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei63Doc

IMPLEMENT_DYNCREATE(CRei63Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei63Doc, CDocument)
END_MESSAGE_MAP()


// CRei63Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei63Doc::CRei63Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei63Doc::~CRei63Doc()
{
}

BOOL CRei63Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei63Doc �V���A����

void CRei63Doc::Serialize(CArchive& ar)
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


// CRei63Doc �f�f

#ifdef _DEBUG
void CRei63Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei63Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei63Doc �R�}���h
