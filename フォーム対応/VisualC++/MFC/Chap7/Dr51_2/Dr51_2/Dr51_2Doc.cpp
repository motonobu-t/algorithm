// Dr51_2Doc.cpp : CDr51_2Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr51_2.h"

#include "Dr51_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr51_2Doc

IMPLEMENT_DYNCREATE(CDr51_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr51_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr51_2Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr51_2Doc::CDr51_2Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr51_2Doc::~CDr51_2Doc()
{
}

BOOL CDr51_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr51_2Doc �V���A����

void CDr51_2Doc::Serialize(CArchive& ar)
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


// CDr51_2Doc �f�f

#ifdef _DEBUG
void CDr51_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr51_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr51_2Doc �R�}���h
