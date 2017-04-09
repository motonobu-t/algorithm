// Rei17View.cpp : CRei17View �N���X�̎���
//

#include "stdafx.h"
#include "Rei17.h"

#include "Rei17Doc.h"
#include "Rei17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei17View

IMPLEMENT_DYNCREATE(CRei17View, CFormView)

BEGIN_MESSAGE_MAP(CRei17View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei17View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei17View �R���X�g���N�V����/�f�X�g���N�V����

CRei17View::CRei17View()
	: CFormView(CRei17View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei17View::~CRei17View()
{
}

void CRei17View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei17View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei17View �f�f

#ifdef _DEBUG
void CRei17View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei17View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei17Doc* CRei17View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei17Doc)));
	return (CRei17Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei17View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      �ŏ��Q��@     *
 * ---------------------
 */

#include "mfcform.h"

#define N 7             /* �f�[�^�� */
#define M 5             /* ���Ă͂ߎ��� */
double ipow(double p,int n)        /* ���O���@�����߂�֐� */
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}

void CRei17View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double x[]={-3,-2,-1, 0,1,2,3},
           y[]={ 5,-2,-3,-1,1,4,5},
           a[M+1][M+2],s[2*M+1],t[M+1];

    int i,j,k;
    double p,d,px;

    for (i=0;i<=2*M;i++)
        s[i]=0;
    for (i=0;i<=M;i++)
        t[i]=0;

    for (i=0;i<N;i++){
        for (j=0;j<=2*M;j++)                /* s0 ���� s2m �̌v�Z */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                  /* t0 ���� tm �̌v�Z */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] �� s[],t[] �̒l������ */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* �͂��o�� */
        p=a[k][k];
        for (j=k;j<=M+1;j++)
            a[k][j]=a[k][j]/p;
        for (i=0;i<=M;i++){
            if (i!=k){
                d=a[i][k];
                for (j=k;j<=M+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

	tinit();cls();
    printf("    x    y\n");        /* ��ԑ������ɂ�邙�̒l�̌v�Z */
    for (px=-3;px<=3;px=px+.5){
        p=0;
        for (k=0;k<=M;k++)
            p=p+a[k][M+1]*ipow(px,k);

        printf("%5.1f%5.1f\n",px,p);
    }
	tfin();
}
