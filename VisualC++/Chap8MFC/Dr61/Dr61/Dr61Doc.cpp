// Dr61Doc.cpp : CDr61Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr61.h"

#include "Dr61Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr61Doc

IMPLEMENT_DYNCREATE(CDr61Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr61Doc, CDocument)
END_MESSAGE_MAP()


// CDr61Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr61Doc::CDr61Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr61Doc::~CDr61Doc()
{
}

BOOL CDr61Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr61Doc �V���A����

void CDr61Doc::Serialize(CArchive& ar)
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


// CDr61Doc �f�f

#ifdef _DEBUG
void CDr61Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr61Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr61Doc �R�}���h
