// Dr65Doc.cpp : CDr65Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr65.h"

#include "Dr65Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr65Doc

IMPLEMENT_DYNCREATE(CDr65Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr65Doc, CDocument)
END_MESSAGE_MAP()


// CDr65Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr65Doc::CDr65Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr65Doc::~CDr65Doc()
{
}

BOOL CDr65Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr65Doc �V���A����

void CDr65Doc::Serialize(CArchive& ar)
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


// CDr65Doc �f�f

#ifdef _DEBUG
void CDr65Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr65Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr65Doc �R�}���h
