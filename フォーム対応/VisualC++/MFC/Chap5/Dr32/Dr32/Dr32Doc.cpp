// Dr32Doc.cpp : CDr32Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr32.h"

#include "Dr32Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr32Doc

IMPLEMENT_DYNCREATE(CDr32Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr32Doc, CDocument)
END_MESSAGE_MAP()


// CDr32Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr32Doc::CDr32Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr32Doc::~CDr32Doc()
{
}

BOOL CDr32Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr32Doc �V���A����

void CDr32Doc::Serialize(CArchive& ar)
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


// CDr32Doc �f�f

#ifdef _DEBUG
void CDr32Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr32Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr32Doc �R�}���h
