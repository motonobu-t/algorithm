// Dr7_1Doc.cpp : CDr7_1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr7_1.h"

#include "Dr7_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr7_1Doc

IMPLEMENT_DYNCREATE(CDr7_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr7_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr7_1Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr7_1Doc::CDr7_1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr7_1Doc::~CDr7_1Doc()
{
}

BOOL CDr7_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr7_1Doc �V���A����

void CDr7_1Doc::Serialize(CArchive& ar)
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


// CDr7_1Doc �f�f

#ifdef _DEBUG
void CDr7_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr7_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr7_1Doc �R�}���h
