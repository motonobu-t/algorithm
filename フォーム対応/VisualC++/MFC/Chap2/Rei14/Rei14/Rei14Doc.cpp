// Rei14Doc.cpp : CRei14Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei14.h"

#include "Rei14Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei14Doc

IMPLEMENT_DYNCREATE(CRei14Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei14Doc, CDocument)
END_MESSAGE_MAP()


// CRei14Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei14Doc::CRei14Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei14Doc::~CRei14Doc()
{
}

BOOL CRei14Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei14Doc �V���A����

void CRei14Doc::Serialize(CArchive& ar)
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


// CRei14Doc �f�f

#ifdef _DEBUG
void CRei14Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei14Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei14Doc �R�}���h
