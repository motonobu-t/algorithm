// Dr17Doc.cpp : CDr17Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr17.h"

#include "Dr17Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr17Doc

IMPLEMENT_DYNCREATE(CDr17Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr17Doc, CDocument)
END_MESSAGE_MAP()


// CDr17Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr17Doc::CDr17Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr17Doc::~CDr17Doc()
{
}

BOOL CDr17Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr17Doc �V���A����

void CDr17Doc::Serialize(CArchive& ar)
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


// CDr17Doc �f�f

#ifdef _DEBUG
void CDr17Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr17Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr17Doc �R�}���h
