// Rei42Doc.cpp : CRei42Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei42.h"

#include "Rei42Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei42Doc

IMPLEMENT_DYNCREATE(CRei42Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei42Doc, CDocument)
END_MESSAGE_MAP()


// CRei42Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei42Doc::CRei42Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei42Doc::~CRei42Doc()
{
}

BOOL CRei42Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei42Doc �V���A����

void CRei42Doc::Serialize(CArchive& ar)
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


// CRei42Doc �f�f

#ifdef _DEBUG
void CRei42Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei42Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei42Doc �R�}���h
