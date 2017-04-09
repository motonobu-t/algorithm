// Dr10_1View.cpp : CDr10_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr10_1.h"

#include "Dr10_1Doc.h"
#include "Dr10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr10_1View

IMPLEMENT_DYNCREATE(CDr10_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr10_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr10_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr10_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr10_1View::CDr10_1View()
	: CFormView(CDr10_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr10_1View::~CDr10_1View()
{
}

void CDr10_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr10_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr10_1View �f�f

#ifdef _DEBUG
void CDr10_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr10_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr10_1Doc* CDr10_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr10_1Doc)));
	return (CDr10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr10_1View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------
 *      �e�C���[�W�J�i�������i���j���ǔŁj     *
 * ---------------------------------------------
 */

#include "mfcform.h"
double myexp(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d,a;
    int k;

    a=fabs(x);
    for (k=1;k<=200;k++){
        d=s;
        e=e*a/k;
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d)){      /* �ł��؂�덷 */
            if (x>0)
                return s;
            else
                return 1.0/s;
        }
    }
    return 0.0;        /* �������Ȃ��Ƃ� */
}

void CDr10_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double x;
	tinit();cls();
    printf("    x       myexp(x)        exp(x)\n");
    for (x=-40;x<=40;x=x+10)
        printf("%5.1f%14.6g%14.6g\n",x,myexp(x),exp(x));
	tfin();
}
