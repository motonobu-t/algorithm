// Dr24Doc.cpp : CDr24Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr24.h"

#include "Dr24Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr24Doc

IMPLEMENT_DYNCREATE(CDr24Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr24Doc, CDocument)
END_MESSAGE_MAP()


// CDr24Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr24Doc::CDr24Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr24Doc::~CDr24Doc()
{
}

BOOL CDr24Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr24Doc �V���A����

void CDr24Doc::Serialize(CArchive& ar)
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


// CDr24Doc �f�f

#ifdef _DEBUG
void CDr24Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr24Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr24Doc �R�}���h
