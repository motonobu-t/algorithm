// Rei3Doc.cpp : CRei3Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei3.h"

#include "Rei3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei3Doc

IMPLEMENT_DYNCREATE(CRei3Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei3Doc, CDocument)
END_MESSAGE_MAP()


// CRei3Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei3Doc::CRei3Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei3Doc::~CRei3Doc()
{
}

BOOL CRei3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei3Doc �V���A����

void CRei3Doc::Serialize(CArchive& ar)
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


// CRei3Doc �f�f

#ifdef _DEBUG
void CRei3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei3Doc �R�}���h
