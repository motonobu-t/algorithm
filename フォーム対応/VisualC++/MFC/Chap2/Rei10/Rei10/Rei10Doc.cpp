// Rei10Doc.cpp : CRei10Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei10.h"

#include "Rei10Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei10Doc

IMPLEMENT_DYNCREATE(CRei10Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei10Doc, CDocument)
END_MESSAGE_MAP()


// CRei10Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei10Doc::CRei10Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei10Doc::~CRei10Doc()
{
}

BOOL CRei10Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei10Doc �V���A����

void CRei10Doc::Serialize(CArchive& ar)
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


// CRei10Doc �f�f

#ifdef _DEBUG
void CRei10Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei10Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei10Doc �R�}���h
