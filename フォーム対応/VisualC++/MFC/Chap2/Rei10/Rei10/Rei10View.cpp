// Rei10View.cpp : CRei10View �N���X�̎���
//

#include "stdafx.h"
#include "Rei10.h"

#include "Rei10Doc.h"
#include "Rei10View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei10View

IMPLEMENT_DYNCREATE(CRei10View, CFormView)

BEGIN_MESSAGE_MAP(CRei10View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei10View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei10View �R���X�g���N�V����/�f�X�g���N�V����

CRei10View::CRei10View()
	: CFormView(CRei10View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei10View::~CRei10View()
{
}

void CRei10View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei10View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei10View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei10View �f�f

#ifdef _DEBUG
void CRei10View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei10View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei10Doc* CRei10View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei10Doc)));
	return (CRei10Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei10View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      �e�C���[�W�J�i�������i���j�j     *
 * ---------------------------------------
 */

#include "mfcform.h"

double myexp(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d;
    int k;

    for (k=1;k<=200;k++) {
        d=s;
        e=e*x/k;
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d))      /* �ł��؂�덷 */
            return s;
    }
    return 0.0;    /* �������Ȃ��Ƃ� */
}

void CRei10View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double x;
	tinit();cls();
    printf("    x      myexp(x)        exp(x)\n");
    for (x=0;x<=40;x=x+10)
        printf("%5.1f%14.6g%14.6g\n",x,myexp(x),exp(x));
	tfin();
}
