// Rei16Doc.cpp : CRei16Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei16.h"

#include "Rei16Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei16Doc

IMPLEMENT_DYNCREATE(CRei16Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei16Doc, CDocument)
END_MESSAGE_MAP()


// CRei16Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei16Doc::CRei16Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei16Doc::~CRei16Doc()
{
}

BOOL CRei16Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei16Doc �V���A����

void CRei16Doc::Serialize(CArchive& ar)
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


// CRei16Doc �f�f

#ifdef _DEBUG
void CRei16Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei16Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei16Doc �R�}���h
