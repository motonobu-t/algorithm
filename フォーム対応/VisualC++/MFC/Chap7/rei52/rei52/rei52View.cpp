// rei52View.cpp : Crei52View �N���X�̎���
//

#include "stdafx.h"
#include "rei52.h"

#include "rei52Doc.h"
#include "rei52View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei52View

IMPLEMENT_DYNCREATE(Crei52View, CFormView)

BEGIN_MESSAGE_MAP(Crei52View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Crei52View::OnBnClickedButton1)
END_MESSAGE_MAP()

// Crei52View �R���X�g���N�V����/�f�X�g���N�V����

Crei52View::Crei52View()
	: CFormView(Crei52View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

Crei52View::~Crei52View()
{
}

void Crei52View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL Crei52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void Crei52View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Crei52View �f�f

#ifdef _DEBUG
void Crei52View::AssertValid() const
{
	CFormView::AssertValid();
}

void Crei52View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Crei52Doc* Crei52View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crei52Doc)));
	return (Crei52Doc*)m_pDocument;
}
#endif //_DEBUG


// Crei52View ���b�Z�[�W �n���h��
/*
 * ---------------------------------
 *      �O���t�̒T���i���D��j     *
 * ---------------------------------
 */

#include "mfcform.h"

#define N 8                                 /* �_�̐� */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},       /* �אڍs�� */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,1,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,0,0,0,0},
                 {0,0,1,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                                 /* �K��t���O */

int queue[100];             /* �L���[ */
int head=0,                 /* �擪�f�[�^�̃C���f�b�N�X */
    tail=0;                 /* �I�[�f�[�^�̃C���f�b�N�X */

void Crei52View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,j;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;

    queue[tail++]=1;v[1]=1;
    do {
        i=queue[head++];            /* �L���[������o�� */
        for (j=1;j<=N;j++){
            if (a[i][j]==1 && v[j]==0){
                printf("%d->%d ",i,j);
                queue[tail++]=j;    /* �L���[�ɓ���� */
                v[j]=1;
            }
        }
    } while (head!=tail);
    printf("\n");
	tfin();
}
