// Dr47View.cpp : CDr47View �N���X�̎���
//

#include "stdafx.h"
#include "Dr47.h"

#include "Dr47Doc.h"
#include "Dr47View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr47View

IMPLEMENT_DYNCREATE(CDr47View, CFormView)

BEGIN_MESSAGE_MAP(CDr47View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr47View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr47View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr47View �R���X�g���N�V����/�f�X�g���N�V����

CDr47View::CDr47View()
	: CFormView(CDr47View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr47View::~CDr47View()
{
}

void CDr47View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr47View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr47View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr47View �f�f

#ifdef _DEBUG
void CDr47View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr47View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr47Doc* CDr47View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr47Doc)));
	return (CDr47Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr47View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *      �q�[�v�̍쐬�i�����ړ��j     *
 * -----------------------------------
 */

#include "mfcform.h"

int heap[100],n=1;

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

void CDr47View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
    n++;
}

void CDr47View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,p,s,m;
    m=n-1;                     /* �f�[�^�� */
    for (i=m/2;i>=1;i--){
        p=i;                 /* �e�̈ʒu */
        s=2*p;               /* ���̎q�̈ʒu */
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* ���ƉE�̎q�̏������� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
        }
    }

	tinit();cls();
	for (i=1;i<=m;i++)
        printf("%d ",heap[i]);
    printf("\n");
	tfin();
}
