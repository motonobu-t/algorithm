// Dr44_2Doc.cpp : CDr44_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr44_2.h"

#include "Dr44_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr44_2Doc

IMPLEMENT_DYNCREATE(CDr44_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr44_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr44_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr44_2Doc::CDr44_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr44_2Doc::~CDr44_2Doc()
{
}

BOOL CDr44_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr44_2Doc �V���A����

void CDr44_2Doc::Serialize(CArchive& ar)
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


// CDr44_2Doc �f�f

#ifdef _DEBUG
void CDr44_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr44_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr44_2Doc �R�}���h
