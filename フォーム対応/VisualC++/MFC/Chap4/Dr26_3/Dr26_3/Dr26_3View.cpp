// Dr26_3View.cpp : CDr26_3View �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_3.h"

#include "Dr26_3Doc.h"
#include "Dr26_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_3View

IMPLEMENT_DYNCREATE(CDr26_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_3View �R���X�g���N�V����/�f�X�g���N�V����

CDr26_3View::CDr26_3View()
	: CFormView(CDr26_3View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr26_3View::~CDr26_3View()
{
}

void CDr26_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr26_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr26_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_3View �f�f

#ifdef _DEBUG
void CDr26_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_3Doc* CDr26_3View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_3Doc)));
	return (CDr26_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_3View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      �g�����������̕��@�i�ċA�Łj     *
 * ---------------------------------------
 */

#include "mfcform.h"

#define N 4        /* ���� */
double fn(double x,double a[],int i)
{
    if (i==0)
        return a[N];
    else
        return fn(x,a,i-1)*x+a[N-i];
}
void CDr26_3View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double a[]={1,2,3,4,5};
	tinit();cls();
    printf("%f\n",fn(2,a,N));
	tfin();
}
