// Rei45Doc.cpp : CRei45Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei45.h"

#include "Rei45Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei45Doc

IMPLEMENT_DYNCREATE(CRei45Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei45Doc, CDocument)
END_MESSAGE_MAP()


// CRei45Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei45Doc::CRei45Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei45Doc::~CRei45Doc()
{
}

BOOL CRei45Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei45Doc �V���A����

void CRei45Doc::Serialize(CArchive& ar)
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


// CRei45Doc �f�f

#ifdef _DEBUG
void CRei45Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei45Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei45Doc �R�}���h
