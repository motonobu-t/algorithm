// Dr21Doc.cpp : CDr21Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr21.h"

#include "Dr21Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr21Doc

IMPLEMENT_DYNCREATE(CDr21Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr21Doc, CDocument)
END_MESSAGE_MAP()


// CDr21Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr21Doc::CDr21Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr21Doc::~CDr21Doc()
{
}

BOOL CDr21Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr21Doc �V���A����

void CDr21Doc::Serialize(CArchive& ar)
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


// CDr21Doc �f�f

#ifdef _DEBUG
void CDr21Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr21Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr21Doc �R�}���h
