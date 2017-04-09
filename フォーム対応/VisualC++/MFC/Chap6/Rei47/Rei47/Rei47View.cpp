// Rei47View.cpp : CRei47View �N���X�̎���
//

#include "stdafx.h"
#include "Rei47.h"

#include "Rei47Doc.h"
#include "Rei47View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei47View

IMPLEMENT_DYNCREATE(CRei47View, CFormView)

BEGIN_MESSAGE_MAP(CRei47View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei47View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei47View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei47View �R���X�g���N�V����/�f�X�g���N�V����

CRei47View::CRei47View()
	: CFormView(CRei47View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei47View::~CRei47View()
{
}

void CRei47View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei47View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei47View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei47View �f�f

#ifdef _DEBUG
void CRei47View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei47View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei47Doc* CRei47View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei47Doc)));
	return (CRei47Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei47View ���b�Z�[�W �n���h��
/*
 * -----------------------
 *      �q�[�v�̍쐬     *
 * -----------------------
 */

#include "mfcform.h"
int heap[100],n=1;
void CRei47View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int s,p,w;
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
    s=n;
    p=s/2;          /* �e�̈ʒu */
    while (s>=2 && heap[p]>heap[s]){    /* ����ړ� */
        w=heap[p];heap[p]=heap[s];heap[s]=w;
        s=p;p=s/2;
    }
    n++;
}

void CRei47View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int i;
	tinit();cls();
	for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	tfin();
}
