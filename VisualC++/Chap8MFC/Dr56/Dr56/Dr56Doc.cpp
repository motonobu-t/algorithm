// Dr56Doc.cpp : CDr56Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr56.h"

#include "Dr56Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr56Doc

IMPLEMENT_DYNCREATE(CDr56Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr56Doc, CDocument)
END_MESSAGE_MAP()


// CDr56Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr56Doc::CDr56Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr56Doc::~CDr56Doc()
{
}

BOOL CDr56Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr56Doc �V���A����

void CDr56Doc::Serialize(CArchive& ar)
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


// CDr56Doc �f�f

#ifdef _DEBUG
void CDr56Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr56Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr56Doc �R�}���h
