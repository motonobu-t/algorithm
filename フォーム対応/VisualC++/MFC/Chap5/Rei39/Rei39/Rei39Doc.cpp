// Rei39Doc.cpp : CRei39Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei39.h"

#include "Rei39Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei39Doc

IMPLEMENT_DYNCREATE(CRei39Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei39Doc, CDocument)
END_MESSAGE_MAP()


// CRei39Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei39Doc::CRei39Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei39Doc::~CRei39Doc()
{
}

BOOL CRei39Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei39Doc �V���A����

void CRei39Doc::Serialize(CArchive& ar)
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


// CRei39Doc �f�f

#ifdef _DEBUG
void CRei39Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei39Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei39Doc �R�}���h
