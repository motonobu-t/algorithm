// Rei24Doc.cpp : CRei24Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei24.h"

#include "Rei24Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei24Doc

IMPLEMENT_DYNCREATE(CRei24Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei24Doc, CDocument)
END_MESSAGE_MAP()


// CRei24Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei24Doc::CRei24Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei24Doc::~CRei24Doc()
{
}

BOOL CRei24Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei24Doc �V���A����

void CRei24Doc::Serialize(CArchive& ar)
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


// CRei24Doc �f�f

#ifdef _DEBUG
void CRei24Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei24Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei24Doc �R�}���h
