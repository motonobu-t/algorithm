// Dr4Doc.cpp : CDr4Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr4.h"

#include "Dr4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr4Doc

IMPLEMENT_DYNCREATE(CDr4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr4Doc, CDocument)
END_MESSAGE_MAP()


// CDr4Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr4Doc::CDr4Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr4Doc::~CDr4Doc()
{
}

BOOL CDr4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr4Doc �V���A����

void CDr4Doc::Serialize(CArchive& ar)
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


// CDr4Doc �f�f

#ifdef _DEBUG
void CDr4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr4Doc �R�}���h
