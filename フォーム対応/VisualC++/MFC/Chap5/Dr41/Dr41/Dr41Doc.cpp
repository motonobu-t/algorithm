// Dr41Doc.cpp : CDr41Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr41.h"

#include "Dr41Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr41Doc

IMPLEMENT_DYNCREATE(CDr41Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr41Doc, CDocument)
END_MESSAGE_MAP()


// CDr41Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr41Doc::CDr41Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr41Doc::~CDr41Doc()
{
}

BOOL CDr41Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr41Doc �V���A����

void CDr41Doc::Serialize(CArchive& ar)
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


// CDr41Doc �f�f

#ifdef _DEBUG
void CDr41Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr41Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr41Doc �R�}���h
