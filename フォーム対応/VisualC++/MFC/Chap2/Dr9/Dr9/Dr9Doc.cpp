// Dr9Doc.cpp : CDr9Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr9.h"

#include "Dr9Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr9Doc

IMPLEMENT_DYNCREATE(CDr9Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr9Doc, CDocument)
END_MESSAGE_MAP()


// CDr9Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr9Doc::CDr9Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr9Doc::~CDr9Doc()
{
}

BOOL CDr9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr9Doc �V���A����

void CDr9Doc::Serialize(CArchive& ar)
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


// CDr9Doc �f�f

#ifdef _DEBUG
void CDr9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr9Doc �R�}���h
