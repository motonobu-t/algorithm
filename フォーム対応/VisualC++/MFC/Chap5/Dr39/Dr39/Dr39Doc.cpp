// Dr39Doc.cpp : CDr39Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr39.h"

#include "Dr39Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr39Doc

IMPLEMENT_DYNCREATE(CDr39Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr39Doc, CDocument)
END_MESSAGE_MAP()


// CDr39Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr39Doc::CDr39Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr39Doc::~CDr39Doc()
{
}

BOOL CDr39Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr39Doc �V���A����

void CDr39Doc::Serialize(CArchive& ar)
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


// CDr39Doc �f�f

#ifdef _DEBUG
void CDr39Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr39Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr39Doc �R�}���h
