// Rei44Doc.cpp : CRei44Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei44.h"

#include "Rei44Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei44Doc

IMPLEMENT_DYNCREATE(CRei44Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei44Doc, CDocument)
END_MESSAGE_MAP()


// CRei44Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei44Doc::CRei44Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei44Doc::~CRei44Doc()
{
}

BOOL CRei44Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei44Doc �V���A����

void CRei44Doc::Serialize(CArchive& ar)
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


// CRei44Doc �f�f

#ifdef _DEBUG
void CRei44Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei44Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei44Doc �R�}���h
