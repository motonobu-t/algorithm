// Dr55Doc.cpp : CDr55Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr55.h"

#include "Dr55Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr55Doc

IMPLEMENT_DYNCREATE(CDr55Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr55Doc, CDocument)
END_MESSAGE_MAP()


// CDr55Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr55Doc::CDr55Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr55Doc::~CDr55Doc()
{
}

BOOL CDr55Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr55Doc �V���A����

void CDr55Doc::Serialize(CArchive& ar)
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


// CDr55Doc �f�f

#ifdef _DEBUG
void CDr55Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr55Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr55Doc �R�}���h
