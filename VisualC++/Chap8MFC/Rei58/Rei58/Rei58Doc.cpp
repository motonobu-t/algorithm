// Rei58Doc.cpp : CRei58Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei58.h"

#include "Rei58Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei58Doc

IMPLEMENT_DYNCREATE(CRei58Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei58Doc, CDocument)
END_MESSAGE_MAP()


// CRei58Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei58Doc::CRei58Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei58Doc::~CRei58Doc()
{
}

BOOL CRei58Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei58Doc �V���A����

void CRei58Doc::Serialize(CArchive& ar)
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


// CRei58Doc �f�f

#ifdef _DEBUG
void CRei58Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei58Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei58Doc �R�}���h
