// Rei11Doc.cpp : CRei11Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei11.h"

#include "Rei11Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei11Doc

IMPLEMENT_DYNCREATE(CRei11Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei11Doc, CDocument)
END_MESSAGE_MAP()


// CRei11Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei11Doc::CRei11Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei11Doc::~CRei11Doc()
{
}

BOOL CRei11Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei11Doc �V���A����

void CRei11Doc::Serialize(CArchive& ar)
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


// CRei11Doc �f�f

#ifdef _DEBUG
void CRei11Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei11Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei11Doc �R�}���h
