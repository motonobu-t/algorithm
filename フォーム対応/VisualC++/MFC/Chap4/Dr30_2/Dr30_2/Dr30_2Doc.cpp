// Dr30_2Doc.cpp : CDr30_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr30_2.h"

#include "Dr30_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_2Doc

IMPLEMENT_DYNCREATE(CDr30_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr30_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr30_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr30_2Doc::CDr30_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr30_2Doc::~CDr30_2Doc()
{
}

BOOL CDr30_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr30_2Doc �V���A����

void CDr30_2Doc::Serialize(CArchive& ar)
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


// CDr30_2Doc �f�f

#ifdef _DEBUG
void CDr30_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr30_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr30_2Doc �R�}���h
