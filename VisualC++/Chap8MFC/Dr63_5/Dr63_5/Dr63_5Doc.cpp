// Dr63_5Doc.cpp : CDr63_5Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_5.h"

#include "Dr63_5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_5Doc

IMPLEMENT_DYNCREATE(CDr63_5Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr63_5Doc, CDocument)
END_MESSAGE_MAP()


// CDr63_5Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr63_5Doc::CDr63_5Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr63_5Doc::~CDr63_5Doc()
{
}

BOOL CDr63_5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr63_5Doc �V���A����

void CDr63_5Doc::Serialize(CArchive& ar)
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


// CDr63_5Doc �f�f

#ifdef _DEBUG
void CDr63_5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr63_5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr63_5Doc �R�}���h
