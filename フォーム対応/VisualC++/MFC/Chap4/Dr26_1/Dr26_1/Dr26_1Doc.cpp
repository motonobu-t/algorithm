// Dr26_1Doc.cpp : CDr26_1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_1.h"

#include "Dr26_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_1Doc

IMPLEMENT_DYNCREATE(CDr26_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_1Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr26_1Doc::CDr26_1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr26_1Doc::~CDr26_1Doc()
{
}

BOOL CDr26_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr26_1Doc �V���A����

void CDr26_1Doc::Serialize(CArchive& ar)
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


// CDr26_1Doc �f�f

#ifdef _DEBUG
void CDr26_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_1Doc �R�}���h
