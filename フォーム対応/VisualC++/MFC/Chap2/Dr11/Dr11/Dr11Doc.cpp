// Dr11Doc.cpp : CDr11Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr11.h"

#include "Dr11Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr11Doc

IMPLEMENT_DYNCREATE(CDr11Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr11Doc, CDocument)
END_MESSAGE_MAP()


// CDr11Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr11Doc::CDr11Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr11Doc::~CDr11Doc()
{
}

BOOL CDr11Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr11Doc �V���A����

void CDr11Doc::Serialize(CArchive& ar)
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


// CDr11Doc �f�f

#ifdef _DEBUG
void CDr11Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr11Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr11Doc �R�}���h
