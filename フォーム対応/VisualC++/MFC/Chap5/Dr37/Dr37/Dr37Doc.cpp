// Dr37Doc.cpp : CDr37Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr37.h"

#include "Dr37Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr37Doc

IMPLEMENT_DYNCREATE(CDr37Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr37Doc, CDocument)
END_MESSAGE_MAP()


// CDr37Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr37Doc::CDr37Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr37Doc::~CDr37Doc()
{
}

BOOL CDr37Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr37Doc �V���A����

void CDr37Doc::Serialize(CArchive& ar)
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


// CDr37Doc �f�f

#ifdef _DEBUG
void CDr37Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr37Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr37Doc �R�}���h
