// Dr13Doc.cpp : CDr13Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr13.h"

#include "Dr13Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr13Doc

IMPLEMENT_DYNCREATE(CDr13Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr13Doc, CDocument)
END_MESSAGE_MAP()


// CDr13Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr13Doc::CDr13Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr13Doc::~CDr13Doc()
{
}

BOOL CDr13Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr13Doc �V���A����

void CDr13Doc::Serialize(CArchive& ar)
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


// CDr13Doc �f�f

#ifdef _DEBUG
void CDr13Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr13Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr13Doc �R�}���h
