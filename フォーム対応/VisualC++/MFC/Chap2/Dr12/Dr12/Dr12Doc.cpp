// Dr12Doc.cpp : CDr12Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr12.h"

#include "Dr12Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr12Doc

IMPLEMENT_DYNCREATE(CDr12Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr12Doc, CDocument)
END_MESSAGE_MAP()


// CDr12Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr12Doc::CDr12Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr12Doc::~CDr12Doc()
{
}

BOOL CDr12Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr12Doc �V���A����

void CDr12Doc::Serialize(CArchive& ar)
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


// CDr12Doc �f�f

#ifdef _DEBUG
void CDr12Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr12Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr12Doc �R�}���h
