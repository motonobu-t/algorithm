// Dr1_2LabelDoc.cpp : CDr1_2LabelDoc �N���X�̎���
//

#include "stdafx.h"
#include "Dr1_2Label.h"

#include "Dr1_2LabelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr1_2LabelDoc

IMPLEMENT_DYNCREATE(CDr1_2LabelDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr1_2LabelDoc, CDocument)
END_MESSAGE_MAP()


// CDr1_2LabelDoc �R���X�g���N�V����/�f�X�g���N�V����

CDr1_2LabelDoc::CDr1_2LabelDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr1_2LabelDoc::~CDr1_2LabelDoc()
{
}

BOOL CDr1_2LabelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr1_2LabelDoc �V���A����

void CDr1_2LabelDoc::Serialize(CArchive& ar)
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


// CDr1_2LabelDoc �f�f

#ifdef _DEBUG
void CDr1_2LabelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr1_2LabelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr1_2LabelDoc �R�}���h
