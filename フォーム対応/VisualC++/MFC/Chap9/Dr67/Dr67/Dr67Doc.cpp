// Dr67Doc.cpp : CDr67Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr67.h"

#include "Dr67Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr67Doc

IMPLEMENT_DYNCREATE(CDr67Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr67Doc, CDocument)
END_MESSAGE_MAP()


// CDr67Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr67Doc::CDr67Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr67Doc::~CDr67Doc()
{
}

BOOL CDr67Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr67Doc �V���A����

void CDr67Doc::Serialize(CArchive& ar)
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


// CDr67Doc �f�f

#ifdef _DEBUG
void CDr67Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr67Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr67Doc �R�}���h
