// Dr64Doc.cpp : CDr64Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr64.h"

#include "Dr64Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr64Doc

IMPLEMENT_DYNCREATE(CDr64Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr64Doc, CDocument)
END_MESSAGE_MAP()


// CDr64Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr64Doc::CDr64Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr64Doc::~CDr64Doc()
{
}

BOOL CDr64Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr64Doc �V���A����

void CDr64Doc::Serialize(CArchive& ar)
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


// CDr64Doc �f�f

#ifdef _DEBUG
void CDr64Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr64Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr64Doc �R�}���h
