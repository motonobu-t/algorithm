// Dr4View.cpp : CDr4View �N���X�̎���
//

#include "stdafx.h"
#include "Dr4.h"

#include "Dr4Doc.h"
#include "Dr4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr4View

IMPLEMENT_DYNCREATE(CDr4View, CFormView)

BEGIN_MESSAGE_MAP(CDr4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr4View �R���X�g���N�V����/�f�X�g���N�V����

CDr4View::CDr4View()
	: CFormView(CDr4View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr4View::~CDr4View()
{
}

void CDr4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr4View �f�f

#ifdef _DEBUG
void CDr4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr4Doc* CDr4View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr4Doc)));
	return (CDr4Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr4View ���b�Z�[�W �n���h��
/*
 * ------------------------------------
 *      �����_���ȏ���i���ǔŁj      *
 * ------------------------------------
 */

#include "mfcform.h"

#define N 20
int irnd(int n)        /* �P�`���̗��� */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}
void CDr4View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,j,d,a[N+1];

	for (i=1;i<=N;i++)
        a[i]=i;

    for (i=N;i>1;i--){
        j=irnd(i-1);
        d=a[i];a[i]=a[j];a[j]=d;
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
