// Rei9Doc.cpp : CRei9Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei9.h"

#include "Rei9Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei9Doc

IMPLEMENT_DYNCREATE(CRei9Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei9Doc, CDocument)
END_MESSAGE_MAP()


// CRei9Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei9Doc::CRei9Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei9Doc::~CRei9Doc()
{
}

BOOL CRei9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei9Doc �V���A����

void CRei9Doc::Serialize(CArchive& ar)
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


// CRei9Doc �f�f

#ifdef _DEBUG
void CRei9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei9Doc �R�}���h
