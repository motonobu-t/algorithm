// Dr29Doc.cpp : CDr29Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr29.h"

#include "Dr29Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr29Doc

IMPLEMENT_DYNCREATE(CDr29Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr29Doc, CDocument)
END_MESSAGE_MAP()


// CDr29Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr29Doc::CDr29Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr29Doc::~CDr29Doc()
{
}

BOOL CDr29Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr29Doc �V���A����

void CDr29Doc::Serialize(CArchive& ar)
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


// CDr29Doc �f�f

#ifdef _DEBUG
void CDr29Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr29Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr29Doc �R�}���h
