// Rei64View.cpp : CRei64View �N���X�̎���
//

#include "stdafx.h"
#include "Rei64.h"

#include "Rei64Doc.h"
#include "Rei64View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei64View

IMPLEMENT_DYNCREATE(CRei64View, CFormView)

BEGIN_MESSAGE_MAP(CRei64View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei64View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei64View �R���X�g���N�V����/�f�X�g���N�V����

CRei64View::CRei64View()
	: CFormView(CRei64View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei64View::~CRei64View()
{
}

void CRei64View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei64View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei64View �f�f

#ifdef _DEBUG
void CRei64View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei64View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei64Doc* CRei64View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei64Doc)));
	return (CRei64Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei64View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      ������w     *
 * ---------------------
 */
#include "mfcform.h"

#define N 7     /* �����w(n=3,5,7,9,���) */

void CRei64View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int hojin[N+1][N+1],i,j,k;
	tinit();cls();
    j=(N+1)/2; i=0;
    for (k=1;k<=N*N;k++){
        if ((k%N)==1)
            i++;
        else {
            i--; j++;
        }
        if (i==0)
            i=N;
        if (j>N)
            j=1;
        hojin[i][j]=k;
    }

    printf("        ������w (N=%d)\n",N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++)
            printf("%4d",hojin[i][j]);
        printf("\n");
    }
	tfin();
}
