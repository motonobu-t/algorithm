// Rei65Doc.cpp : CRei65Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei65.h"

#include "Rei65Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei65Doc

IMPLEMENT_DYNCREATE(CRei65Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei65Doc, CDocument)
END_MESSAGE_MAP()


// CRei65Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei65Doc::CRei65Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei65Doc::~CRei65Doc()
{
}

BOOL CRei65Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei65Doc �V���A����

void CRei65Doc::Serialize(CArchive& ar)
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


// CRei65Doc �f�f

#ifdef _DEBUG
void CRei65Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei65Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei65Doc �R�}���h
