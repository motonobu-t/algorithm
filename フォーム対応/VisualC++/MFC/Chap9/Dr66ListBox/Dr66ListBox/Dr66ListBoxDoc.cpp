// Dr66ListBoxDoc.cpp : CDr66ListBoxDoc �N���X�̎���
//

#include "stdafx.h"
#include "Dr66ListBox.h"

#include "Dr66ListBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66ListBoxDoc

IMPLEMENT_DYNCREATE(CDr66ListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr66ListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CDr66ListBoxDoc �R���X�g���N�V����/�f�X�g���N�V����

CDr66ListBoxDoc::CDr66ListBoxDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr66ListBoxDoc::~CDr66ListBoxDoc()
{
}

BOOL CDr66ListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr66ListBoxDoc �V���A����

void CDr66ListBoxDoc::Serialize(CArchive& ar)
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


// CDr66ListBoxDoc �f�f

#ifdef _DEBUG
void CDr66ListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr66ListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr66ListBoxDoc �R�}���h
