// Dr17MFCDoc.cpp : CDr17MFCDoc �N���X�̎���
//

#include "stdafx.h"
#include "Dr17MFC.h"

#include "Dr17MFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr17MFCDoc

IMPLEMENT_DYNCREATE(CDr17MFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr17MFCDoc, CDocument)
END_MESSAGE_MAP()


// CDr17MFCDoc �R���X�g���N�V����/�f�X�g���N�V����

CDr17MFCDoc::CDr17MFCDoc()
{
	// TODO: ���̈ʒu�� 1 �x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CDr17MFCDoc::~CDr17MFCDoc()
{
}

BOOL CDr17MFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CDr17MFCDoc �V���A����

void CDr17MFCDoc::Serialize(CArchive& ar)
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


// CDr17MFCDoc �f�f

#ifdef _DEBUG
void CDr17MFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr17MFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr17MFCDoc �R�}���h
