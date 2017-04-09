// Rei14View.cpp : CRei14View �N���X�̎���
//

#include "stdafx.h"
#include "Rei14.h"

#include "Rei14Doc.h"
#include "Rei14View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei14View

IMPLEMENT_DYNCREATE(CRei14View, CFormView)

BEGIN_MESSAGE_MAP(CRei14View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei14View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei14View �R���X�g���N�V����/�f�X�g���N�V����

CRei14View::CRei14View()
	: CFormView(CRei14View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei14View::~CRei14View()
{
}

void CRei14View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei14View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei14View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei14View �f�f

#ifdef _DEBUG
void CRei14View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei14View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei14Doc* CRei14View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei14Doc)));
	return (CRei14Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei14View ���b�Z�[�W �n���h��
/*
 * -----------------------
 *      �΂̑����v�Z     *
 * -----------------------
 */

#include "mfcform.h"

#define L 1000                    /* ���߂錅��     */
#define L1 ((L/4)+1)              /* �z��̃T�C�Y   */
#define L2 (L1+1)                 /* ��]���Ɏ�� */
#define N (short)(L/1.39794+1)    /* �v�Z���鍀��   */
void printresult(short c[])      /* ���ʂ̕\�� */
{
    short i;
    printf("%3d. ",c[0]);        /* �ŏ�ʌ��̕\�� */
	for (i=1;i<L1;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])    /* �����O���{�����O�� */
{
    short i,cy=0;
    for (i=L2;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])    /* �����O���|�����O�� */
{
    short i,brrw=0;
    for (i=L2;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void ldiv(short a[],short b,short c[])      /* �����O���������O�� */
{
    short i;long d,rem=0;
    for (i=0;i<=L2;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}

void CRei14View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    short s[L2+2],w[L2+2],v[L2+2],q[L2+2];
    short k;

    for (k=0;k<=L2;k++)
        s[k]=w[k]=v[k]=q[k]=0;

    w[0]=16*5; v[0]=4*239;            /* �}�`���̌��� */
    for (k=1;k<=N;k++){
        ldiv(w,25,w);
        ldiv(v,239,v);ldiv(v,239,v);
        lsub(w,v,q);ldiv(q,2*k-1,q);
        if ((k%2)!=0)                 /* ��������������̔��� */
            ladd(s,q,s);
        else
            lsub(s,q,s);
    }

	tinit();cls();
    printresult(s);
	tfin();
}
