// Dr48_2View.cpp : CDr48_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr48_2.h"

#include "Dr48_2Doc.h"
#include "Dr48_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr48_2View

IMPLEMENT_DYNCREATE(CDr48_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr48_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr48_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr48_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr48_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr48_2View::CDr48_2View()
	: CFormView(CDr48_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr48_2View::~CDr48_2View()
{
}

void CDr48_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr48_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr48_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr48_2View �f�f

#ifdef _DEBUG
void CDr48_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr48_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr48_2Doc* CDr48_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr48_2Doc)));
	return (CDr48_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr48_2View ���b�Z�[�W �n���h��
/*
 * -------------------------
 *      �q�[�v�E�\�[�g     *
 * -------------------------
 */

#include "mfcform.h"

int heap[100],n=1;
void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}
void shiftdown(int p,int n,int heap[])   /* �����ړ� */
{
    int s;
    s=2*p;
    while (s<=n){
        if( s<n && heap[s+1]>heap[s])    /* ���ƉE�̎q�̑傫���� */
            s++;
        if (heap[p]>=heap[s])
            break;
        swap(&heap[p],&heap[s]);
        p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
    }
}
void CDr48_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
	n++;
}

void CDr48_2View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int i,m;
	m=n-1;                        /* ���̕ۑ� */
    for (i=m/2;i>=1;i--)        /* �����q�[�v�̍쐬 */
        shiftdown(i,m,heap);
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* �؂̏I�[��؂藣�� */
        shiftdown(1,m,heap);
    }
	tinit();cls();
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	n=1;  // �ŏ������蒼��
	tfin();
}
