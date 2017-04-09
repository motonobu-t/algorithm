// Dr14_2ListBoxView.cpp : CDr14_2ListBoxView �N���X�̎���
//

#include "stdafx.h"
#include "Dr14_2ListBox.h"

#include "Dr14_2ListBoxDoc.h"
#include "Dr14_2ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_2ListBoxView

IMPLEMENT_DYNCREATE(CDr14_2ListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CDr14_2ListBoxView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr14_2ListBoxView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr14_2ListBoxView �R���X�g���N�V����/�f�X�g���N�V����

CDr14_2ListBoxView::CDr14_2ListBoxView()
	: CFormView(CDr14_2ListBoxView::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr14_2ListBoxView::~CDr14_2ListBoxView()
{
}

void CDr14_2ListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}

BOOL CDr14_2ListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr14_2ListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr14_2ListBoxView �f�f

#ifdef _DEBUG
void CDr14_2ListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr14_2ListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr14_2ListBoxDoc* CDr14_2ListBoxView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr14_2ListBoxDoc)));
	return (CDr14_2ListBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CDr14_2ListBoxView ���b�Z�[�W �n���h��
/*
 * -------------------------
 *      �K��̑����v�Z     *
 * -------------------------
 */
#define L 64               /* ���߂錅��      */
#define L2 ((L+3)/4)       /* �z��̃T�C�Y    */

CListBox *LB;		// ���X�g�{�b�N�X
CString cbuf,		//	�����ϊ��p			
        outstr;		//�@�P�s�o�͗p

void printresult(short c[])       /* ���ʂ̕\�� */
{
    short i;
	for (i=0;i<L2;i++){
        cbuf.Format(CString("%04d"),c[i]);
		outstr+=cbuf;
	}
    LB->InsertString(-1,CString(outstr));
}
void lmul(short a[],short b,short c[])    /* �����O���~�V���[�g�� */
{
    short i;long d,cy=0;
    for (i=L2-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
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

void CDr14_2ListBoxView::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	LB=(CListBox *)GetDlgItem(IDC_LIST1);
	short s[L2];
    short k;
    for (k=0;k<L2;k++)
        s[k]=0;

    s[L2-1]=1;
    for (k=1;k<=49;k++){
        lmul(s,k,s);
        outstr.Format(CString("%2d!="),k);
        printresult(s);
    }
}
