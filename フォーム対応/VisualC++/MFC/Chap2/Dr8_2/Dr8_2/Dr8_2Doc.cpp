// Dr8_2Doc.cpp : CDr8_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr8_2.h"

#include "Dr8_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr8_2Doc

IMPLEMENT_DYNCREATE(CDr8_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr8_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr8_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr8_2Doc::CDr8_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr8_2Doc::~CDr8_2Doc()
{
}

BOOL CDr8_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr8_2Doc �V���A����

void CDr8_2Doc::Serialize(CArchive& ar)
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


// CDr8_2Doc �f�f

#ifdef _DEBUG
void CDr8_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr8_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr8_2Doc �R�}���h
