// Dr25Doc.cpp : CDr25Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr25.h"

#include "Dr25Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr25Doc

IMPLEMENT_DYNCREATE(CDr25Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr25Doc, CDocument)
END_MESSAGE_MAP()


// CDr25Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr25Doc::CDr25Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr25Doc::~CDr25Doc()
{
}

BOOL CDr25Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr25Doc �V���A����

void CDr25Doc::Serialize(CArchive& ar)
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


// CDr25Doc �f�f

#ifdef _DEBUG
void CDr25Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr25Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr25Doc �R�}���h
