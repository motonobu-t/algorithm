// Dr31Doc.cpp : CDr31Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr31.h"

#include "Dr31Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr31Doc

IMPLEMENT_DYNCREATE(CDr31Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr31Doc, CDocument)
END_MESSAGE_MAP()


// CDr31Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr31Doc::CDr31Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr31Doc::~CDr31Doc()
{
}

BOOL CDr31Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr31Doc �V���A����

void CDr31Doc::Serialize(CArchive& ar)
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


// CDr31Doc �f�f

#ifdef _DEBUG
void CDr31Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr31Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr31Doc �R�}���h
