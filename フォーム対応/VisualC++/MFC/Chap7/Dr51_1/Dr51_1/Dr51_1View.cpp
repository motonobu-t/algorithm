// Dr51_1View.cpp : CDr51_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr51_1.h"

#include "Dr51_1Doc.h"
#include "Dr51_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr51_1View

IMPLEMENT_DYNCREATE(CDr51_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr51_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr51_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr51_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr51_1View::CDr51_1View()
	: CFormView(CDr51_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr51_1View::~CDr51_1View()
{
}

void CDr51_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr51_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr51_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr51_1View �f�f

#ifdef _DEBUG
void CDr51_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr51_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr51_1Doc* CDr51_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr51_1Doc)));
	return (CDr51_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr51_1View ���b�Z�[�W �n���h��
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

void CDr51_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,k;
	tinit();cls();
    for (k=1;k<=N;k++){
        for (i=1;i<=N;i++)
            v[i]=0;
        visit(k);
        printf("\n");
    }
	tfin();
}
