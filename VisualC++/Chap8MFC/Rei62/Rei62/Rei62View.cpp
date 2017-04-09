// Rei62View.cpp : CRei62View �N���X�̎���
//

#include "stdafx.h"
#include "Rei62.h"

#include "Rei62Doc.h"
#include "Rei62View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei62View

IMPLEMENT_DYNCREATE(CRei62View, CView)

BEGIN_MESSAGE_MAP(CRei62View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei62View �R���X�g���N�V����/�f�X�g���N�V����

CRei62View::CRei62View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei62View::~CRei62View()
{
}

BOOL CRei62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CRei62View �`��
/*
 * -----------------------
 *       �R�b�z�Ȑ�      *
 * -----------------------
 */

#include "mfcglib.h"
void koch(int n,double leng)        /* �R�b�z�Ȑ��̍ċA�葱�� */
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}

void CRei62View::OnDraw(CDC* pDC)
{
	CRei62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int    n=4;         /* �R�b�z���� */
    double leng=4.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

    koch(n,leng);

}


// CRei62View ���

BOOL CRei62View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CRei62View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRei62View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CRei62View �f�f

#ifdef _DEBUG
void CRei62View::AssertValid() const
{
	CView::AssertValid();
}

void CRei62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei62Doc* CRei62View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei62Doc)));
	return (CRei62Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei62View ���b�Z�[�W �n���h��
