// Dr35_2Doc.cpp : CDr35_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr35_2.h"

#include "Dr35_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr35_2Doc

IMPLEMENT_DYNCREATE(CDr35_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr35_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr35_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr35_2Doc::CDr35_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr35_2Doc::~CDr35_2Doc()
{
}

BOOL CDr35_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr35_2Doc �V���A����

void CDr35_2Doc::Serialize(CArchive& ar)
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


// CDr35_2Doc �f�f

#ifdef _DEBUG
void CDr35_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr35_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr35_2Doc �R�}���h
