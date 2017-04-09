// Dr14_1View.cpp : CDr14_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr14_1.h"

#include "Dr14_1Doc.h"
#include "Dr14_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_1View

IMPLEMENT_DYNCREATE(CDr14_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr14_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr14_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr14_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr14_1View::CDr14_1View()
	: CFormView(CDr14_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr14_1View::~CDr14_1View()
{
}

void CDr14_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr14_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr14_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr14_1View �f�f

#ifdef _DEBUG
void CDr14_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr14_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr14_1Doc* CDr14_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr14_1Doc)));
	return (CDr14_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr14_1View ���b�Z�[�W �n���h��
/*
 * -----------------------
 *      ���̑����v�Z     *
 * -----------------------
 */

#include "mfcform.h"

#define L 1000          /* ���߂錅��      */
#define L1 ((L/4)+1)    /* �z��̃T�C�Y    */
#define L2 (L1+1)       /* ��]���Ɏ��  */
#define N 451           /* �v�Z���鍀��    */
void printresult(short c[])       /* ���ʂ̕\�� */
{
    short i;
    printf("%3d. ",c[0]);         /* �ŏ�ʌ��̕\�� */
	for (i=1;i<L1;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
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
void lsub(short a[],short b[],short c[])
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
void ldiv(short a[],short b,short c[])    /* �����O�����V���[�g�� */
{
    short i;long d,rem=0;
    for (i=0;i<=L2;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}

void CDr14_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    short s[L2+2],w[L2+2];
    short k;

    for (k=0;k<=L2;k++)
        s[k]=w[k]=0;

    s[0]=w[0]=1;
    for (k=1;k<=N;k++){
        ldiv(w,k,w);
        ladd(s,w,s);
    }

	tinit();cls();
    printresult(s);
	tfin();
}
