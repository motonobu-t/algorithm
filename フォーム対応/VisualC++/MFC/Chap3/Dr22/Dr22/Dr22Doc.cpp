// Dr22Doc.cpp : CDr22Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr22.h"

#include "Dr22Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr22Doc

IMPLEMENT_DYNCREATE(CDr22Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr22Doc, CDocument)
END_MESSAGE_MAP()


// CDr22Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr22Doc::CDr22Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr22Doc::~CDr22Doc()
{
}

BOOL CDr22Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr22Doc �V���A����

void CDr22Doc::Serialize(CArchive& ar)
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


// CDr22Doc �f�f

#ifdef _DEBUG
void CDr22Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr22Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr22Doc �R�}���h
