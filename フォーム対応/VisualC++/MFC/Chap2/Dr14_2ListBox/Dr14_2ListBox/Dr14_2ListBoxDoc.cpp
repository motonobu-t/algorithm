// Dr14_2ListBoxDoc.cpp : CDr14_2ListBoxDoc �N���X�̎���
//

#include "stdafx.h"
#include "Dr14_2ListBox.h"

#include "Dr14_2ListBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_2ListBoxDoc

IMPLEMENT_DYNCREATE(CDr14_2ListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr14_2ListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CDr14_2ListBoxDoc �R���X�g���N�V����/�f�X�g���N�V����

CDr14_2ListBoxDoc::CDr14_2ListBoxDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr14_2ListBoxDoc::~CDr14_2ListBoxDoc()
{
}

BOOL CDr14_2ListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr14_2ListBoxDoc �V���A����

void CDr14_2ListBoxDoc::Serialize(CArchive& ar)
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


// CDr14_2ListBoxDoc �f�f

#ifdef _DEBUG
void CDr14_2ListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr14_2ListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr14_2ListBoxDoc �R�}���h
