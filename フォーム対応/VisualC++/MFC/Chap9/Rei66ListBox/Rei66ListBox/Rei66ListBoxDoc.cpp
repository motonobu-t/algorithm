// Rei66ListBoxDoc.cpp : CRei66ListBoxDoc �N���X�̎���
//

#include "stdafx.h"
#include "Rei66ListBox.h"

#include "Rei66ListBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66ListBoxDoc

IMPLEMENT_DYNCREATE(CRei66ListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CRei66ListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CRei66ListBoxDoc �R���X�g���N�V����/�f�X�g���N�V����

CRei66ListBoxDoc::CRei66ListBoxDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei66ListBoxDoc::~CRei66ListBoxDoc()
{
}

BOOL CRei66ListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei66ListBoxDoc �V���A����

void CRei66ListBoxDoc::Serialize(CArchive& ar)
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


// CRei66ListBoxDoc �f�f

#ifdef _DEBUG
void CRei66ListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei66ListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei66ListBoxDoc �R�}���h
