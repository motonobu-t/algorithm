// Dr30_3Doc.cpp : CDr30_3Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr30_3.h"

#include "Dr30_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_3Doc

IMPLEMENT_DYNCREATE(CDr30_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr30_3Doc, CDocument)
END_MESSAGE_MAP()


// CDr30_3Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr30_3Doc::CDr30_3Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr30_3Doc::~CDr30_3Doc()
{
}

BOOL CDr30_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr30_3Doc �V���A����

void CDr30_3Doc::Serialize(CArchive& ar)
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


// CDr30_3Doc �f�f

#ifdef _DEBUG
void CDr30_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr30_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr30_3Doc �R�}���h
