// Dr20_1Doc.cpp : CDr20_1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr20_1.h"

#include "Dr20_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_1Doc

IMPLEMENT_DYNCREATE(CDr20_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr20_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr20_1Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr20_1Doc::CDr20_1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr20_1Doc::~CDr20_1Doc()
{
}

BOOL CDr20_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr20_1Doc �V���A����

void CDr20_1Doc::Serialize(CArchive& ar)
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


// CDr20_1Doc �f�f

#ifdef _DEBUG
void CDr20_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr20_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr20_1Doc �R�}���h
