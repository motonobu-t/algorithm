// Rei4Doc.cpp : CRei4Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei4.h"

#include "Rei4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei4Doc

IMPLEMENT_DYNCREATE(CRei4Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei4Doc, CDocument)
END_MESSAGE_MAP()


// CRei4Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei4Doc::CRei4Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei4Doc::~CRei4Doc()
{
}

BOOL CRei4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei4Doc �V���A����

void CRei4Doc::Serialize(CArchive& ar)
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


// CRei4Doc �f�f

#ifdef _DEBUG
void CRei4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei4Doc �R�}���h
