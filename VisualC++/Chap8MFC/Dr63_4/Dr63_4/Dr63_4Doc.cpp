// Dr63_4Doc.cpp : CDr63_4Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_4.h"

#include "Dr63_4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_4Doc

IMPLEMENT_DYNCREATE(CDr63_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr63_4Doc, CDocument)
END_MESSAGE_MAP()


// CDr63_4Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr63_4Doc::CDr63_4Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr63_4Doc::~CDr63_4Doc()
{
}

BOOL CDr63_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr63_4Doc �V���A����

void CDr63_4Doc::Serialize(CArchive& ar)
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


// CDr63_4Doc �f�f

#ifdef _DEBUG
void CDr63_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr63_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr63_4Doc �R�}���h
