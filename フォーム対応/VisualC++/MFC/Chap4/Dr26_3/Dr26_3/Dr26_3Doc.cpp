// Dr26_3Doc.cpp : CDr26_3Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_3.h"

#include "Dr26_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_3Doc

IMPLEMENT_DYNCREATE(CDr26_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_3Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_3Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr26_3Doc::CDr26_3Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr26_3Doc::~CDr26_3Doc()
{
}

BOOL CDr26_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr26_3Doc �V���A����

void CDr26_3Doc::Serialize(CArchive& ar)
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


// CDr26_3Doc �f�f

#ifdef _DEBUG
void CDr26_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_3Doc �R�}���h
