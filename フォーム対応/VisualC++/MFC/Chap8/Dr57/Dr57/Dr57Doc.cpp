// Dr57Doc.cpp : CDr57Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr57.h"

#include "Dr57Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr57Doc

IMPLEMENT_DYNCREATE(CDr57Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr57Doc, CDocument)
END_MESSAGE_MAP()


// CDr57Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr57Doc::CDr57Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr57Doc::~CDr57Doc()
{
}

BOOL CDr57Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr57Doc �V���A����

void CDr57Doc::Serialize(CArchive& ar)
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


// CDr57Doc �f�f

#ifdef _DEBUG
void CDr57Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr57Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr57Doc �R�}���h
