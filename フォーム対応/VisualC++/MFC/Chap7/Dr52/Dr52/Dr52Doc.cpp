// Dr52Doc.cpp : CDr52Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr52.h"

#include "Dr52Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr52Doc

IMPLEMENT_DYNCREATE(CDr52Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr52Doc, CDocument)
END_MESSAGE_MAP()


// CDr52Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr52Doc::CDr52Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr52Doc::~CDr52Doc()
{
}

BOOL CDr52Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr52Doc �V���A����

void CDr52Doc::Serialize(CArchive& ar)
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


// CDr52Doc �f�f

#ifdef _DEBUG
void CDr52Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr52Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr52Doc �R�}���h
