// Rei25Doc.cpp : CRei25Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei25.h"

#include "Rei25Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei25Doc

IMPLEMENT_DYNCREATE(CRei25Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei25Doc, CDocument)
END_MESSAGE_MAP()


// CRei25Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei25Doc::CRei25Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei25Doc::~CRei25Doc()
{
}

BOOL CRei25Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei25Doc �V���A����

void CRei25Doc::Serialize(CArchive& ar)
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


// CRei25Doc �f�f

#ifdef _DEBUG
void CRei25Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei25Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei25Doc �R�}���h
