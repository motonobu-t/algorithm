// Dr47Doc.cpp : CDr47Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr47.h"

#include "Dr47Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr47Doc

IMPLEMENT_DYNCREATE(CDr47Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr47Doc, CDocument)
END_MESSAGE_MAP()


// CDr47Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr47Doc::CDr47Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr47Doc::~CDr47Doc()
{
}

BOOL CDr47Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr47Doc �V���A����

void CDr47Doc::Serialize(CArchive& ar)
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


// CDr47Doc �f�f

#ifdef _DEBUG
void CDr47Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr47Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr47Doc �R�}���h
