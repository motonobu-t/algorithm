// Rei5Doc.cpp : CRei5Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei5.h"

#include "Rei5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei5Doc

IMPLEMENT_DYNCREATE(CRei5Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei5Doc, CDocument)
END_MESSAGE_MAP()


// CRei5Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei5Doc::CRei5Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei5Doc::~CRei5Doc()
{
}

BOOL CRei5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei5Doc �V���A����

void CRei5Doc::Serialize(CArchive& ar)
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


// CRei5Doc �f�f

#ifdef _DEBUG
void CRei5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei5Doc �R�}���h
