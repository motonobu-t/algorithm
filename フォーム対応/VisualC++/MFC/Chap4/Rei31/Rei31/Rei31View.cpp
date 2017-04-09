// Rei31View.cpp : CRei31View �N���X�̎���
//

#include "stdafx.h"
#include "Rei31.h"

#include "Rei31Doc.h"
#include "Rei31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei31View

IMPLEMENT_DYNCREATE(CRei31View, CFormView)

BEGIN_MESSAGE_MAP(CRei31View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei31View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CRei31View::OnStnClickedPict)
END_MESSAGE_MAP()

// CRei31View �R���X�g���N�V����/�f�X�g���N�V����

CRei31View::CRei31View()
	: CFormView(CRei31View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei31View::~CRei31View()
{
}

void CRei31View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei31View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei31View �f�f

#ifdef _DEBUG
void CRei31View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei31View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei31Doc* CRei31View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei31Doc)));
	return (CRei31Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei31View ���b�Z�[�W �n���h��
/*
 * ---------------------------
 *      �N�C�b�N�E�\�[�g     *
 * ---------------------------
 */

#include "mfcform.h"

#define N 10
void quick(int a[],int left,int right)
{
    int s,t,i,j;

    if (left<right){
        s=a[left];              /* ���[�̍������ɂ��� */
        i=left; j=right+1;      /* ����菬�����O���[�v��       */
        while (1){              /*       �傫���O���[�v�ɕ����� */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
        a[left]=a[j]; a[j]=s;   /* ���𐳂����ʒu�ɓ���� */

        quick(a,left,j-1);      /* ��������ɑ΂���ċA�Ăяo�� */
        quick(a,j+1,right);     /* �E������ɑ΂���ċA�Ăяo�� */
    }
}

void CRei31View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    static int a[]={41,24,76,11,45,64,21,69,19,36};
    int k;

    quick(a,0,N-1);
	tinit();cls();
    for (k=0;k<N;k++)
        printf("%4d",a[k]);
    printf("\n");
	tfin();
}
