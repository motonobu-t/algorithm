// Dr14_2View.cpp : CDr14_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr14_2.h"

#include "Dr14_2Doc.h"
#include "Dr14_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_2View

IMPLEMENT_DYNCREATE(CDr14_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr14_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr14_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr14_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr14_2View::CDr14_2View()
	: CFormView(CDr14_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr14_2View::~CDr14_2View()
{
}

void CDr14_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr14_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr14_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr14_2View �f�f

#ifdef _DEBUG
void CDr14_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr14_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr14_2Doc* CDr14_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr14_2Doc)));
	return (CDr14_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr14_2View ���b�Z�[�W �n���h��
/*
 * -------------------------
 *      �K��̑����v�Z     *
 * -------------------------
 */

#include "mfcform.h"

#define L 64               /* ���߂錅��      */
#define L2 ((L+3)/4)       /* �z��̃T�C�Y    */
void lmul(short a[],short b,short c[])    /* �����O���~�V���[�g�� */
{
    short i;long d,cy=0;
    for (i=L2-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}

void printresult(short c[])       /* ���ʂ̕\�� */
{
    short i;
    for (i=0;i<L2;i++)
        printf("%04d",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2-1;i>=0;i--){
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
    for (i=L2-1;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}

void CDr14_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    short s[L2];
    short k;

    for (k=0;k<L2;k++)
        s[k]=0;

    s[L2-1]=1;
	tinit();cls();
    for (k=1;k<=49;k++){
        lmul(s,k,s);
        printf("%2d!=",k);
        printresult(s);
    }
	tfin();
}
