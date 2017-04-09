// Rei12View.cpp : CRei12View �N���X�̎���
//

#include "stdafx.h"
#include "Rei12.h"

#include "Rei12Doc.h"
#include "Rei12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei12View

IMPLEMENT_DYNCREATE(CRei12View, CFormView)

BEGIN_MESSAGE_MAP(CRei12View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei12View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei12View �R���X�g���N�V����/�f�X�g���N�V����

CRei12View::CRei12View()
	: CFormView(CRei12View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei12View::~CRei12View()
{
}

void CRei12View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei12View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei12View �f�f

#ifdef _DEBUG
void CRei12View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei12View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei12Doc* CRei12View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei12Doc)));
	return (CRei12Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei12View ���b�Z�[�W �n���h��
/*
 * ---------------------------
 *      ���O�����W�����     *
 * ---------------------------
 */

#include "mfcform.h"

double lagrange(double x[],double y[],int n,double t)
{
    int i,j;
    double s,p;

    s=0.0;
    for (i=0;i<n;i++){
        p=y[i];
        for (j=0;j<n;j++){
            if (i!=j)
                p=p*(t-x[j])/(x[i]-x[j]);
        }
        s=s+p;
    }
    return s;
}
void CRei12View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double x[]={0.0,1.0,3.0,6.0,7.0},
           y[]={0.8,3.1,4.5,3.9,2.8};

    double t;
	tinit();cls();
    printf("      x      y\n");
    for (t=0.0;t<=7.0;t=t+.5)
        printf("%7.2f%7.2f\n",t,lagrange(x,y,5,t));
	tfin();
}
