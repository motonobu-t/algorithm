// Dr42Doc.cpp : CDr42Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr42.h"

#include "Dr42Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr42Doc

IMPLEMENT_DYNCREATE(CDr42Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr42Doc, CDocument)
END_MESSAGE_MAP()


// CDr42Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr42Doc::CDr42Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr42Doc::~CDr42Doc()
{
}

BOOL CDr42Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr42Doc �V���A����

void CDr42Doc::Serialize(CArchive& ar)
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


// CDr42Doc �f�f

#ifdef _DEBUG
void CDr42Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr42Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr42Doc �R�}���h
