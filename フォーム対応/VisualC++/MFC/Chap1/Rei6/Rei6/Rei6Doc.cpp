// Rei6Doc.cpp : CRei6Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei6.h"

#include "Rei6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei6Doc

IMPLEMENT_DYNCREATE(CRei6Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei6Doc, CDocument)
END_MESSAGE_MAP()


// CRei6Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei6Doc::CRei6Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei6Doc::~CRei6Doc()
{
}

BOOL CRei6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei6Doc �V���A����

void CRei6Doc::Serialize(CArchive& ar)
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


// CRei6Doc �f�f

#ifdef _DEBUG
void CRei6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei6Doc �R�}���h
