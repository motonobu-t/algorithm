// Dr2Doc.cpp : CDr2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr2.h"

#include "Dr2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr2Doc

IMPLEMENT_DYNCREATE(CDr2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr2Doc, CDocument)
END_MESSAGE_MAP()


// CDr2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr2Doc::CDr2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr2Doc::~CDr2Doc()
{
}

BOOL CDr2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr2Doc �V���A����

void CDr2Doc::Serialize(CArchive& ar)
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


// CDr2Doc �f�f

#ifdef _DEBUG
void CDr2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr2Doc �R�}���h
