// Dr49Doc.cpp : CDr49Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr49.h"

#include "Dr49Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr49Doc

IMPLEMENT_DYNCREATE(CDr49Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr49Doc, CDocument)
END_MESSAGE_MAP()


// CDr49Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr49Doc::CDr49Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr49Doc::~CDr49Doc()
{
}

BOOL CDr49Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr49Doc �V���A����

void CDr49Doc::Serialize(CArchive& ar)
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


// CDr49Doc �f�f

#ifdef _DEBUG
void CDr49Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr49Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr49Doc �R�}���h
