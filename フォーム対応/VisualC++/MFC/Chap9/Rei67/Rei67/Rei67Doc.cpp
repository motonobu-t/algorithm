// Rei67Doc.cpp : CRei67Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei67.h"

#include "Rei67Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei67Doc

IMPLEMENT_DYNCREATE(CRei67Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei67Doc, CDocument)
END_MESSAGE_MAP()


// CRei67Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei67Doc::CRei67Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei67Doc::~CRei67Doc()
{
}

BOOL CRei67Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei67Doc �V���A����

void CRei67Doc::Serialize(CArchive& ar)
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


// CRei67Doc �f�f

#ifdef _DEBUG
void CRei67Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei67Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei67Doc �R�}���h
