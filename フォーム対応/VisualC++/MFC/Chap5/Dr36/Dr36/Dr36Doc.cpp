// Dr36Doc.cpp : CDr36Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr36.h"

#include "Dr36Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr36Doc

IMPLEMENT_DYNCREATE(CDr36Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr36Doc, CDocument)
END_MESSAGE_MAP()


// CDr36Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr36Doc::CDr36Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr36Doc::~CDr36Doc()
{
}

BOOL CDr36Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr36Doc �V���A����

void CDr36Doc::Serialize(CArchive& ar)
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


// CDr36Doc �f�f

#ifdef _DEBUG
void CDr36Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr36Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr36Doc �R�}���h
