// Dr66Doc.cpp : CDr66Doc �N���X�̎���
//

#include "stdafx.h"
#include "Dr66.h"

#include "Dr66Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66Doc

IMPLEMENT_DYNCREATE(CDr66Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr66Doc, CDocument)
END_MESSAGE_MAP()


// CDr66Doc �R���X�g���N�V����/�f�X�g���N�V����

CDr66Doc::CDr66Doc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr66Doc::~CDr66Doc()
{
}

BOOL CDr66Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr66Doc �V���A����

void CDr66Doc::Serialize(CArchive& ar)
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


// CDr66Doc �f�f

#ifdef _DEBUG
void CDr66Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr66Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr66Doc �R�}���h
