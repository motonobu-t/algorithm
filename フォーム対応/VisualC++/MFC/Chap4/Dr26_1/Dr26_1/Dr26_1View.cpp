// Dr26_1View.cpp : CDr26_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_1.h"

#include "Dr26_1Doc.h"
#include "Dr26_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_1View

IMPLEMENT_DYNCREATE(CDr26_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr26_1View::CDr26_1View()
	: CFormView(CDr26_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr26_1View::~CDr26_1View()
{
}

void CDr26_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr26_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr26_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_1View �f�f

#ifdef _DEBUG
void CDr26_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_1Doc* CDr26_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_1Doc)));
	return (CDr26_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_1View ���b�Z�[�W �n���h��
/*
 * ------------------------------------
 *      �t�B�{�i�b�`���i�ċA�Łj      *
 * ------------------------------------
 */

#include "mfcform.h"
long fib(long n)
{
    if (n==1 || n==2)
        return 1L;
    else
        return fib(n-1)+fib(n-2);
}
void CDr26_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    long n;
	tinit();cls();
    for (n=1;n<=20;n++)
        printf("%3ld: %ld\n",n,fib(n));
	tfin();
}
