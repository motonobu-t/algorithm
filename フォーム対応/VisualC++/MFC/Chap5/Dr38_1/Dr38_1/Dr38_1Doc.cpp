// Dr38_1Doc.cpp : CDr38_1Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr38_1.h"

#include "Dr38_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr38_1Doc

IMPLEMENT_DYNCREATE(CDr38_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr38_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr38_1Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr38_1Doc::CDr38_1Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr38_1Doc::~CDr38_1Doc()
{
}

BOOL CDr38_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr38_1Doc �V���A����

void CDr38_1Doc::Serialize(CArchive& ar)
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


// CDr38_1Doc �f�f

#ifdef _DEBUG
void CDr38_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr38_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr38_1Doc �R�}���h
