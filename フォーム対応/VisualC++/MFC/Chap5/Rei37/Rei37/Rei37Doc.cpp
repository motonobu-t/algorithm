// Rei37Doc.cpp : CRei37Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei37.h"

#include "Rei37Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei37Doc

IMPLEMENT_DYNCREATE(CRei37Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei37Doc, CDocument)
END_MESSAGE_MAP()


// CRei37Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei37Doc::CRei37Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei37Doc::~CRei37Doc()
{
}

BOOL CRei37Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei37Doc �V���A����

void CRei37Doc::Serialize(CArchive& ar)
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


// CRei37Doc �f�f

#ifdef _DEBUG
void CRei37Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei37Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei37Doc �R�}���h
