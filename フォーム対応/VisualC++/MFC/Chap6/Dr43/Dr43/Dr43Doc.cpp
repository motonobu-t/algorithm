// Dr43Doc.cpp : CDr43Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr43.h"

#include "Dr43Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr43Doc

IMPLEMENT_DYNCREATE(CDr43Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr43Doc, CDocument)
END_MESSAGE_MAP()


// CDr43Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr43Doc::CDr43Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr43Doc::~CDr43Doc()
{
}

BOOL CDr43Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr43Doc �V���A����

void CDr43Doc::Serialize(CArchive& ar)
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


// CDr43Doc �f�f

#ifdef _DEBUG
void CDr43Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr43Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr43Doc �R�}���h
