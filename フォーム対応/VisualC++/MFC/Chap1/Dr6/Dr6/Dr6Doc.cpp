// Dr6Doc.cpp : CDr6Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr6.h"

#include "Dr6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr6Doc

IMPLEMENT_DYNCREATE(CDr6Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr6Doc, CDocument)
END_MESSAGE_MAP()


// CDr6Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr6Doc::CDr6Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr6Doc::~CDr6Doc()
{
}

BOOL CDr6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr6Doc �V���A����

void CDr6Doc::Serialize(CArchive& ar)
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


// CDr6Doc �f�f

#ifdef _DEBUG
void CDr6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr6Doc �R�}���h
