// Dr28_2View.cpp : CDr28_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr28_2.h"

#include "Dr28_2Doc.h"
#include "Dr28_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr28_2View

IMPLEMENT_DYNCREATE(CDr28_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr28_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr28_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr28_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr28_2View::CDr28_2View()
	: CFormView(CDr28_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr28_2View::~CDr28_2View()
{
}

void CDr28_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr28_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr28_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr28_2View �f�f

#ifdef _DEBUG
void CDr28_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr28_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr28_2Doc* CDr28_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr28_2Doc)));
	return (CDr28_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr28_2View ���b�Z�[�W �n���h��
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
            t=p[j];                 /* p[i]�`p[j]�̉E���[�e�C�g */
            for (k=j;k>i;k--)
                p[k]=p[k-1];
            p[i]=t;

            perm(i+1);              /* �ċA�Ăяo�� */

            for (k=i;k<j;k++)       /* �z��̕��т��ċA�Ăяo���O�ɖ߂� */
                p[k]=p[k+1];
            p[j]=t;
        }
    }
    else {
        for (j=1;j<=N-1;j++)        /* ����̕\�� */
            printf("%c",p[j]);
        printf("\n");
    }
}

void CDr28_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;

    for (i=1;i<=N;i++)        /* �����ݒ� */
        p[i]=i;
        
    p[1]='a';p[2]='c';p[3]='h';p[4]='t';
	tinit();cls();
    perm(1);
	tfin();
}
