// Dr26_2Doc.cpp : CDr26_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_2.h"

#include "Dr26_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_2Doc

IMPLEMENT_DYNCREATE(CDr26_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr26_2Doc::CDr26_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr26_2Doc::~CDr26_2Doc()
{
}

BOOL CDr26_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr26_2Doc �V���A����

void CDr26_2Doc::Serialize(CArchive& ar)
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


// CDr26_2Doc �f�f

#ifdef _DEBUG
void CDr26_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_2Doc �R�}���h
