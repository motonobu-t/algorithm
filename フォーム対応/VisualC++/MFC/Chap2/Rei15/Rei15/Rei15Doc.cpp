// Rei15Doc.cpp : CRei15Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei15.h"

#include "Rei15Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei15Doc

IMPLEMENT_DYNCREATE(CRei15Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei15Doc, CDocument)
END_MESSAGE_MAP()


// CRei15Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei15Doc::CRei15Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei15Doc::~CRei15Doc()
{
}

BOOL CRei15Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei15Doc �V���A����

void CRei15Doc::Serialize(CArchive& ar)
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


// CRei15Doc �f�f

#ifdef _DEBUG
void CRei15Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei15Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei15Doc �R�}���h
