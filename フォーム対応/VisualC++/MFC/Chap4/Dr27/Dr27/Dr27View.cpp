// Dr27View.cpp : CDr27View �N���X�̎���
//

#include "stdafx.h"
#include "Dr27.h"

#include "Dr27Doc.h"
#include "Dr27View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr27View

IMPLEMENT_DYNCREATE(CDr27View, CFormView)

BEGIN_MESSAGE_MAP(CDr27View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr27View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr27View �R���X�g���N�V����/�f�X�g���N�V����

CDr27View::CDr27View()
	: CFormView(CDr27View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr27View::~CDr27View()
{
}

void CDr27View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr27View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr27View �f�f

#ifdef _DEBUG
void CDr27View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr27View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr27Doc* CDr27View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr27Doc)));
	return (CDr27Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr27View ���b�Z�[�W �n���h��
/*
 * --------------------------------------
 *      �t�B�{�i�b�`���i��ċA�Łj      *
 * --------------------------------------
 */

#include "mfcform.h"
long fib(long n)
{
    long a,b,dummy,k;
    a=1L; b=1L;
    for (k=3;k<=n;k++){
        dummy=b;
        b=a+b;
        a=dummy;
    }
    return b;
}

void CDr27View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    long n;
	tinit();cls();
    for (n=1;n<=20;n++)
        printf("%3ld: %ld\n",n,fib(n));
	tfin();
}
