// Dr46Doc.cpp : CDr46Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr46.h"

#include "Dr46Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr46Doc

IMPLEMENT_DYNCREATE(CDr46Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr46Doc, CDocument)
END_MESSAGE_MAP()


// CDr46Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr46Doc::CDr46Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr46Doc::~CDr46Doc()
{
}

BOOL CDr46Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr46Doc �V���A����

void CDr46Doc::Serialize(CArchive& ar)
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


// CDr46Doc �f�f

#ifdef _DEBUG
void CDr46Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr46Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr46Doc �R�}���h
