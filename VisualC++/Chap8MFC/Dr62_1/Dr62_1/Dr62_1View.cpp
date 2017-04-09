// Dr62_1View.cpp : CDr62_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr62_1.h"

#include "Dr62_1Doc.h"
#include "Dr62_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_1View

IMPLEMENT_DYNCREATE(CDr62_1View, CView)

BEGIN_MESSAGE_MAP(CDr62_1View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr62_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr62_1View::CDr62_1View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr62_1View::~CDr62_1View()
{
}

BOOL CDr62_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr62_1View �`��
/*
 * ---------------------
 *       �R�b�z��      *
 * ---------------------
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

void CDr62_1View::OnDraw(CDC* pDC)
{
	CDr62_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int    i,
           n=4;         /* �R�b�z���� */
    double leng=4.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(150,300);
    setangle(0);
    for (i=0;i<3;i++){
          koch(n,leng);
        turn(-120);
    }

}


// CDr62_1View ���

BOOL CDr62_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr62_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr62_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr62_1View �f�f

#ifdef _DEBUG
void CDr62_1View::AssertValid() const
{
	CView::AssertValid();
}

void CDr62_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr62_1Doc* CDr62_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr62_1Doc)));
	return (CDr62_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr62_1View ���b�Z�[�W �n���h��
