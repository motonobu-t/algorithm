// Dr27Doc.cpp : CDr27Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr27.h"

#include "Dr27Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr27Doc

IMPLEMENT_DYNCREATE(CDr27Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr27Doc, CDocument)
END_MESSAGE_MAP()


// CDr27Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr27Doc::CDr27Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr27Doc::~CDr27Doc()
{
}

BOOL CDr27Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr27Doc �V���A����

void CDr27Doc::Serialize(CArchive& ar)
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


// CDr27Doc �f�f

#ifdef _DEBUG
void CDr27Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr27Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr27Doc �R�}���h
