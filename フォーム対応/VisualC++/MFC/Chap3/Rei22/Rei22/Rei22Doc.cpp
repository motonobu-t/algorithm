// Rei22Doc.cpp : CRei22Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei22.h"

#include "Rei22Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei22Doc

IMPLEMENT_DYNCREATE(CRei22Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei22Doc, CDocument)
END_MESSAGE_MAP()


// CRei22Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei22Doc::CRei22Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei22Doc::~CRei22Doc()
{
}

BOOL CRei22Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei22Doc �V���A����

void CRei22Doc::Serialize(CArchive& ar)
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


// CRei22Doc �f�f

#ifdef _DEBUG
void CRei22Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei22Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei22Doc �R�}���h
