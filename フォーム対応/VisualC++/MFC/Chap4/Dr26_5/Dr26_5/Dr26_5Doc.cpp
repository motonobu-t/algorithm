// Dr26_5Doc.cpp : CDr26_5Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_5.h"

#include "Dr26_5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_5Doc

IMPLEMENT_DYNCREATE(CDr26_5Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_5Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_5Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr26_5Doc::CDr26_5Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr26_5Doc::~CDr26_5Doc()
{
}

BOOL CDr26_5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr26_5Doc �V���A����

void CDr26_5Doc::Serialize(CArchive& ar)
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


// CDr26_5Doc �f�f

#ifdef _DEBUG
void CDr26_5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_5Doc �R�}���h
