// Dr23Doc.cpp : CDr23Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr23.h"

#include "Dr23Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr23Doc

IMPLEMENT_DYNCREATE(CDr23Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr23Doc, CDocument)
END_MESSAGE_MAP()


// CDr23Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr23Doc::CDr23Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr23Doc::~CDr23Doc()
{
}

BOOL CDr23Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr23Doc �V���A����

void CDr23Doc::Serialize(CArchive& ar)
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


// CDr23Doc �f�f

#ifdef _DEBUG
void CDr23Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr23Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr23Doc �R�}���h
