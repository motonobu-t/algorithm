// Dr59Doc.cpp : CDr59Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr59.h"

#include "Dr59Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr59Doc

IMPLEMENT_DYNCREATE(CDr59Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr59Doc, CDocument)
END_MESSAGE_MAP()


// CDr59Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr59Doc::CDr59Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr59Doc::~CDr59Doc()
{
}

BOOL CDr59Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr59Doc �V���A����

void CDr59Doc::Serialize(CArchive& ar)
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


// CDr59Doc �f�f

#ifdef _DEBUG
void CDr59Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr59Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr59Doc �R�}���h
