// Rei20Doc.cpp : CRei20Doc �N���X�̎���
//

#include "stdafx.h"
#include "Rei20.h"

#include "Rei20Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei20Doc

IMPLEMENT_DYNCREATE(CRei20Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei20Doc, CDocument)
END_MESSAGE_MAP()


// CRei20Doc �R���X�g���N�V����/�f�X�g���N�V����

CRei20Doc::CRei20Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CRei20Doc::~CRei20Doc()
{
}

BOOL CRei20Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CRei20Doc �V���A����

void CRei20Doc::Serialize(CArchive& ar)
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


// CRei20Doc �f�f

#ifdef _DEBUG
void CRei20Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei20Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei20Doc �R�}���h
