// Rei28Doc.cpp : CRei28Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei28.h"

#include "Rei28Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei28Doc

IMPLEMENT_DYNCREATE(CRei28Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei28Doc, CDocument)
END_MESSAGE_MAP()


// CRei28Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei28Doc::CRei28Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei28Doc::~CRei28Doc()
{
}

BOOL CRei28Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei28Doc �V���A����

void CRei28Doc::Serialize(CArchive& ar)
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


// CRei28Doc �f�f

#ifdef _DEBUG
void CRei28Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei28Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei28Doc �R�}���h
