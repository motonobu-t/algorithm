// Dr60Doc.cpp : CDr60Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr60.h"

#include "Dr60Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr60Doc

IMPLEMENT_DYNCREATE(CDr60Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr60Doc, CDocument)
END_MESSAGE_MAP()


// CDr60Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr60Doc::CDr60Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr60Doc::~CDr60Doc()
{
}

BOOL CDr60Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr60Doc �V���A����

void CDr60Doc::Serialize(CArchive& ar)
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


// CDr60Doc �f�f

#ifdef _DEBUG
void CDr60Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr60Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr60Doc �R�}���h
