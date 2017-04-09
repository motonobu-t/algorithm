// Rei28View.cpp : CRei28View �N���X�̎���
//

#include "stdafx.h"
#include "Rei28.h"

#include "Rei28Doc.h"
#include "Rei28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei28View

IMPLEMENT_DYNCREATE(CRei28View, CFormView)

BEGIN_MESSAGE_MAP(CRei28View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei28View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei28View �R���X�g���N�V����/�f�X�g���N�V����

CRei28View::CRei28View()
	: CFormView(CRei28View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei28View::~CRei28View()
{
}

void CRei28View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei28View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei28View �f�f

#ifdef _DEBUG
void CRei28View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei28View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei28Doc* CRei28View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei28Doc)));
	return (CRei28Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei28View ���b�Z�[�W �n���h��
/*
 * -------------------------------------
 *      ���񐶐��i���������łȂ��j     *
 * -------------------------------------
 */

#include "mfcform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[i]; p[i]=p[j]; p[j]=t;    /* p[i]��p[j]�̌��� */
            perm(i+1);                    /* �ċA�Ăяo�� */
            t=p[i]; p[i]=p[j]; p[j]=t;    /* ���ɖ߂� */
        }
    }
    else {
        for (j=1;j<=N;j++)                /* ����̕\�� */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void CRei28View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;

    for (i=1;i<=N;i++)        /* �����ݒ� */
        p[i]=i;
	tinit();cls();  // �ċA�Ăяo���̑O���tinit()��tfin()������
    perm(1);
	tfin();
}
