// Rei30Doc.cpp : CRei30Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei30.h"

#include "Rei30Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei30Doc

IMPLEMENT_DYNCREATE(CRei30Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei30Doc, CDocument)
END_MESSAGE_MAP()


// CRei30Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei30Doc::CRei30Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei30Doc::~CRei30Doc()
{
}

BOOL CRei30Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei30Doc �V���A����

void CRei30Doc::Serialize(CArchive& ar)
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


// CRei30Doc �f�f

#ifdef _DEBUG
void CRei30Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei30Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei30Doc �R�}���h
