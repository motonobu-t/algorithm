// Rei53View.cpp : CRei53View �N���X�̎���
//

#include "stdafx.h"
#include "Rei53.h"

#include "Rei53Doc.h"
#include "Rei53View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei53View

IMPLEMENT_DYNCREATE(CRei53View, CFormView)

BEGIN_MESSAGE_MAP(CRei53View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei53View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei53View �R���X�g���N�V����/�f�X�g���N�V����

CRei53View::CRei53View()
	: CFormView(CRei53View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei53View::~CRei53View()
{
}

void CRei53View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei53View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei53View �f�f

#ifdef _DEBUG
void CRei53View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei53View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei53Doc* CRei53View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei53Doc)));
	return (CRei53Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei53View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      �g�|���W�J���E�\�[�g     *
 * -------------------------------
 */
#include "mfcform.h"

#define N 8                             /* �_�̐� */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* �אڍs�� */
                 {0,0,0,1,0,0,0,0,0},
                 {0,1,0,0,0,1,0,0,0},
                 {0,0,0,0,1,0,0,1,0},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,0,0,1,1},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,1,0}};
int v[N+1];                             /* �K��t���O */
void visit(int i)
{
    int j;
    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0)
            visit(j);
    }
    printf("%d ",i);
}

void CRei53View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++)
        if (v[i]==0)
            visit(i);
    printf("\n");
	tfin();
}
