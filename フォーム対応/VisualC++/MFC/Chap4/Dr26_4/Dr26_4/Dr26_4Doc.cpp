// Dr26_4Doc.cpp : CDr26_4Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_4.h"

#include "Dr26_4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_4Doc

IMPLEMENT_DYNCREATE(CDr26_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_4Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_4Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr26_4Doc::CDr26_4Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr26_4Doc::~CDr26_4Doc()
{
}

BOOL CDr26_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr26_4Doc �V���A����

void CDr26_4Doc::Serialize(CArchive& ar)
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


// CDr26_4Doc �f�f

#ifdef _DEBUG
void CDr26_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_4Doc �R�}���h
