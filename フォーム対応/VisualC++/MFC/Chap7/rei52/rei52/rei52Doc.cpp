// rei52Doc.cpp : Crei52Doc �N���X�̎���
//

#include "stdafx.h"
#include "rei52.h"

#include "rei52Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei52Doc

IMPLEMENT_DYNCREATE(Crei52Doc, CDocument)

BEGIN_MESSAGE_MAP(Crei52Doc, CDocument)
END_MESSAGE_MAP()


// Crei52Doc �R���X�g���N�V����/�f�X�g���N�V����

Crei52Doc::Crei52Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

Crei52Doc::~Crei52Doc()
{
}

BOOL Crei52Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// Crei52Doc �V���A����

void Crei52Doc::Serialize(CArchive& ar)
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


// Crei52Doc �f�f

#ifdef _DEBUG
void Crei52Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Crei52Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Crei52Doc �R�}���h
