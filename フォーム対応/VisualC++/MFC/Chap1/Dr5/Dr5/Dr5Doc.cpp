// Dr5Doc.cpp : CDr5Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr5.h"

#include "Dr5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr5Doc

IMPLEMENT_DYNCREATE(CDr5Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr5Doc, CDocument)
END_MESSAGE_MAP()


// CDr5Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr5Doc::CDr5Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr5Doc::~CDr5Doc()
{
}

BOOL CDr5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr5Doc �V���A����

void CDr5Doc::Serialize(CArchive& ar)
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


// CDr5Doc �f�f

#ifdef _DEBUG
void CDr5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr5Doc �R�}���h
