// Dr14_1Doc.cpp : CDr14_1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr14_1.h"

#include "Dr14_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_1Doc

IMPLEMENT_DYNCREATE(CDr14_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr14_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr14_1Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr14_1Doc::CDr14_1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr14_1Doc::~CDr14_1Doc()
{
}

BOOL CDr14_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr14_1Doc �V���A����

void CDr14_1Doc::Serialize(CArchive& ar)
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


// CDr14_1Doc �f�f

#ifdef _DEBUG
void CDr14_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr14_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr14_1Doc �R�}���h
