// rei54Doc.cpp : Crei54Doc �N���X�̎���
//

#include "stdafx.h"
#include "rei54.h"

#include "rei54Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei54Doc

IMPLEMENT_DYNCREATE(Crei54Doc, CDocument)

BEGIN_MESSAGE_MAP(Crei54Doc, CDocument)
END_MESSAGE_MAP()


// Crei54Doc �R���X�g���N�V����/�f�X�g���N�V����

Crei54Doc::Crei54Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

Crei54Doc::~Crei54Doc()
{
}

BOOL Crei54Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// Crei54Doc �V���A����

void Crei54Doc::Serialize(CArchive& ar)
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


// Crei54Doc �f�f

#ifdef _DEBUG
void Crei54Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Crei54Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Crei54Doc �R�}���h
