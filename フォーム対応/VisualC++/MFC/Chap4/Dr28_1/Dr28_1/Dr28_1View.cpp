// Dr28_1View.cpp : CDr28_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr28_1.h"

#include "Dr28_1Doc.h"
#include "Dr28_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr28_1View

IMPLEMENT_DYNCREATE(CDr28_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr28_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr28_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr28_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr28_1View::CDr28_1View()
	: CFormView(CDr28_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr28_1View::~CDr28_1View()
{
}

void CDr28_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr28_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr28_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr28_1View �f�f

#ifdef _DEBUG
void CDr28_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr28_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr28_1Doc* CDr28_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr28_1Doc)));
	return (CDr28_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr28_1View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      ���񐶐��i���������j     *
 * -------------------------------
 */

#include "mfcform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,k,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[j];                  /* p[i]�`p[j]�̉E���[�e�C�g */
            for (k=j;k>i;k--)
                p[k]=p[k-1];
            p[i]=t;

            perm(i+1);               /* �ċA�Ăяo�� */

            for (k=i;k<j;k++)        /* �z��̕��т��ċA�Ăяo���O�ɖ߂� */
                p[k]=p[k+1];
            p[j]=t;
        }
    }
    else {
        for (j=1;j<=N;j++)           /* ����̕\�� */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void CDr28_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;

    for (i=1;i<=N;i++)        /* �����ݒ� */
        p[i]=i;
	tinit();cls();
    perm(1);
	tfin();
}
