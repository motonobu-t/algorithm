// Dr53Doc.cpp : CDr53Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr53.h"

#include "Dr53Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr53Doc

IMPLEMENT_DYNCREATE(CDr53Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr53Doc, CDocument)
END_MESSAGE_MAP()


// CDr53Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr53Doc::CDr53Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr53Doc::~CDr53Doc()
{
}

BOOL CDr53Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr53Doc �V���A����

void CDr53Doc::Serialize(CArchive& ar)
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


// CDr53Doc �f�f

#ifdef _DEBUG
void CDr53Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr53Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr53Doc �R�}���h
