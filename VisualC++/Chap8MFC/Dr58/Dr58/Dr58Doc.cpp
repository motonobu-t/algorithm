// Dr58Doc.cpp : CDr58Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr58.h"

#include "Dr58Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr58Doc

IMPLEMENT_DYNCREATE(CDr58Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr58Doc, CDocument)
END_MESSAGE_MAP()


// CDr58Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr58Doc::CDr58Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr58Doc::~CDr58Doc()
{
}

BOOL CDr58Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr58Doc �V���A����

void CDr58Doc::Serialize(CArchive& ar)
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


// CDr58Doc �f�f

#ifdef _DEBUG
void CDr58Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr58Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr58Doc �R�}���h
