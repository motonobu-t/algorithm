// Rei59Doc.cpp : CRei59Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei59.h"

#include "Rei59Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei59Doc

IMPLEMENT_DYNCREATE(CRei59Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei59Doc, CDocument)
END_MESSAGE_MAP()


// CRei59Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei59Doc::CRei59Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei59Doc::~CRei59Doc()
{
}

BOOL CRei59Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei59Doc �V���A����

void CRei59Doc::Serialize(CArchive& ar)
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


// CRei59Doc �f�f

#ifdef _DEBUG
void CRei59Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei59Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei59Doc �R�}���h
