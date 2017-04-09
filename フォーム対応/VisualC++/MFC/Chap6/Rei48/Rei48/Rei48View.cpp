// Rei48View.cpp : CRei48View �N���X�̎���
//

#include "stdafx.h"
#include "Rei48.h"

#include "Rei48Doc.h"
#include "Rei48View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei48View

IMPLEMENT_DYNCREATE(CRei48View, CFormView)

BEGIN_MESSAGE_MAP(CRei48View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei48View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei48View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei48View �R���X�g���N�V����/�f�X�g���N�V����

CRei48View::CRei48View()
	: CFormView(CRei48View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei48View::~CRei48View()
{
}

void CRei48View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei48View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei48View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei48View �f�f

#ifdef _DEBUG
void CRei48View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei48View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei48Doc* CRei48View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei48Doc)));
	return (CRei48Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei48View ���b�Z�[�W �n���h��
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
void CRei48View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int s,p;
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
    s=n;p=s/2;
    while (s>=2 && heap[p]>heap[s]){
        swap(&heap[p],&heap[s]);
        s=p;p=s/2;
    }
    n++;
}

void CRei48View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,s,p,m;
    m=n-1;                /* ���̕ۑ� */
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* �؂̏I�[��؂藣�� */

        p=1; s=2*p;
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* ���ƉE�̏������� */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* �e�Ǝq�̈ʒu�̍X�V */
        }
    }
	tinit();cls();
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	tfin();
	n=1;  // �ŏ������蒼��
}
