// Rei34Doc.cpp : CRei34Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei34.h"

#include "Rei34Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei34Doc

IMPLEMENT_DYNCREATE(CRei34Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei34Doc, CDocument)
END_MESSAGE_MAP()


// CRei34Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei34Doc::CRei34Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei34Doc::~CRei34Doc()
{
}

BOOL CRei34Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei34Doc �V���A����

void CRei34Doc::Serialize(CArchive& ar)
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


// CRei34Doc �f�f

#ifdef _DEBUG
void CRei34Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei34Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei34Doc �R�}���h
