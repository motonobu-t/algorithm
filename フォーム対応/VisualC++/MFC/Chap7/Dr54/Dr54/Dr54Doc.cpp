// Dr54Doc.cpp : CDr54Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr54.h"

#include "Dr54Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr54Doc

IMPLEMENT_DYNCREATE(CDr54Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr54Doc, CDocument)
END_MESSAGE_MAP()


// CDr54Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr54Doc::CDr54Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr54Doc::~CDr54Doc()
{
}

BOOL CDr54Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr54Doc �V���A����

void CDr54Doc::Serialize(CArchive& ar)
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


// CDr54Doc �f�f

#ifdef _DEBUG
void CDr54Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr54Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr54Doc �R�}���h
