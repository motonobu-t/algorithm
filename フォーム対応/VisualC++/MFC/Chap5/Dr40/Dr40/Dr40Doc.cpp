// Dr40Doc.cpp : CDr40Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr40.h"

#include "Dr40Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr40Doc

IMPLEMENT_DYNCREATE(CDr40Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr40Doc, CDocument)
END_MESSAGE_MAP()


// CDr40Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr40Doc::CDr40Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr40Doc::~CDr40Doc()
{
}

BOOL CDr40Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr40Doc �V���A����

void CDr40Doc::Serialize(CArchive& ar)
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


// CDr40Doc �f�f

#ifdef _DEBUG
void CDr40Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr40Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr40Doc �R�}���h
