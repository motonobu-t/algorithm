// Dr63_2Doc.cpp : CDr63_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_2.h"

#include "Dr63_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_2Doc

IMPLEMENT_DYNCREATE(CDr63_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr63_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr63_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr63_2Doc::CDr63_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr63_2Doc::~CDr63_2Doc()
{
}

BOOL CDr63_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr63_2Doc �V���A����

void CDr63_2Doc::Serialize(CArchive& ar)
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


// CDr63_2Doc �f�f

#ifdef _DEBUG
void CDr63_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr63_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr63_2Doc �R�}���h