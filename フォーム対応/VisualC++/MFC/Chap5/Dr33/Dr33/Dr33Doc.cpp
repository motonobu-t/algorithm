// Dr33Doc.cpp : CDr33Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr33.h"

#include "Dr33Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr33Doc

IMPLEMENT_DYNCREATE(CDr33Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr33Doc, CDocument)
END_MESSAGE_MAP()


// CDr33Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr33Doc::CDr33Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr33Doc::~CDr33Doc()
{
}

BOOL CDr33Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr33Doc �V���A����

void CDr33Doc::Serialize(CArchive& ar)
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


// CDr33Doc �f�f

#ifdef _DEBUG
void CDr33Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr33Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr33Doc �R�}���h
