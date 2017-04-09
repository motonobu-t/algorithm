// Rei51View.cpp : CRei51View �N���X�̎���
//

#include "stdafx.h"
#include "Rei51.h"

#include "Rei51Doc.h"
#include "Rei51View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei51View

IMPLEMENT_DYNCREATE(CRei51View, CFormView)

BEGIN_MESSAGE_MAP(CRei51View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei51View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei51View �R���X�g���N�V����/�f�X�g���N�V����

CRei51View::CRei51View()
	: CFormView(CRei51View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei51View::~CRei51View()
{
}

void CRei51View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei51View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei51View �f�f

#ifdef _DEBUG
void CRei51View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei51View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei51Doc* CRei51View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei51Doc)));
	return (CRei51Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei51View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *      �O���t�̒T���i�[���D��j     *
 * -----------------------------------
 */
#include "mfcform.h"

#define N 8                             /* �_�̐� */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* �אڍs�� */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,0,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                             /* �K��t���O */
void visit(int i)
{
    int j;

    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0){
            printf("%d->%d ",i,j);
            visit(j);
        }
    }
}

void CRei51View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    visit(1);
    printf("\n");
	tfin();
}
