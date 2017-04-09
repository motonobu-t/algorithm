// Dr62_2View.cpp : CDr62_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr62_2.h"

#include "Dr62_2Doc.h"
#include "Dr62_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_2View

IMPLEMENT_DYNCREATE(CDr62_2View, CView)

BEGIN_MESSAGE_MAP(CDr62_2View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr62_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr62_2View::CDr62_2View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr62_2View::~CDr62_2View()
{
}

BOOL CDr62_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr62_2View �`��
/*
 * ------------------------------
 *       �N���X�E�X�e�b�`       *
 * ------------------------------
 */

#include "mfcglib.h"

void stech(int n,double leng)       /* �X�e�b�`�̍ċA�葱�� */
{
    if (n==0)
        move(leng);
    else {
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng);
    }
}

void CDr62_2View::OnDraw(CDC* pDC)
{
	CDr62_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int    k,
           n=4;         /* �X�e�b�`�̎��� */
    double leng=2.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(200,150); setangle(0);
    for (k=1;k<=4;k++){
        stech(n,leng);
        turn(90);
    }
}


// CDr62_2View ���

BOOL CDr62_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr62_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr62_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr62_2View �f�f

#ifdef _DEBUG
void CDr62_2View::AssertValid() const
{
	CView::AssertValid();
}

void CDr62_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr62_2Doc* CDr62_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr62_2Doc)));
	return (CDr62_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr62_2View ���b�Z�[�W �n���h��
