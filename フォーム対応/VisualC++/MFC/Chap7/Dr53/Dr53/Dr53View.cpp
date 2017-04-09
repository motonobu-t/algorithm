// Dr53View.cpp : CDr53View �N���X�̎���
//

#include "stdafx.h"
#include "Dr53.h"

#include "Dr53Doc.h"
#include "Dr53View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr53View

IMPLEMENT_DYNCREATE(CDr53View, CFormView)

BEGIN_MESSAGE_MAP(CDr53View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr53View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CDr53View::OnStnClickedPict)
END_MESSAGE_MAP()

// CDr53View �R���X�g���N�V����/�f�X�g���N�V����

CDr53View::CDr53View()
	: CFormView(CDr53View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr53View::~CDr53View()
{
}

void CDr53View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr53View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr53View �f�f

#ifdef _DEBUG
void CDr53View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr53View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr53Doc* CDr53View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr53Doc)));
	return (CDr53Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr53View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------------
 *      �g�|���W�J���E�\�[�g�i�H�̔�����܂ށj     *
 * ---------------------------------------------------
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
int v[N+1],                             /* �K��t���O */
    s[N+1];                             /* �\�[�g���ʊi�[�p */
void visit(int i)
{
    int j;
    static int sp=1;    /* �X�^�b�N�E�|�C���^ */
    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0)
            visit(j);
        if (a[i][j]==1 && v[j]==1){
            printf("%d �� %d �̕t�߂Ƀ��[�v������܂�\n",i,j);
            exit(1);
        }
    }
    v[i]=2;             /* �H�̔���̂��� */
    s[sp++]=i;          /* �X�^�b�N�Ɋi�[   */
}

void CDr53View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++)
        if (v[i]==0)
            visit(i);
    for (i=N;i>=1;i--)
        printf("%d ",s[i]);
    printf("\n");
	tfin();
}

