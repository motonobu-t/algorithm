// Dr34_1Doc.cpp : CDr34_1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr34_1.h"

#include "Dr34_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr34_1Doc

IMPLEMENT_DYNCREATE(CDr34_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr34_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr34_1Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr34_1Doc::CDr34_1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr34_1Doc::~CDr34_1Doc()
{
}

BOOL CDr34_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr34_1Doc �V���A����

void CDr34_1Doc::Serialize(CArchive& ar)
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


// CDr34_1Doc �f�f

#ifdef _DEBUG
void CDr34_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr34_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr34_1Doc �R�}���h
