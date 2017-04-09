// Dr52View.cpp : CDr52View �N���X�̎���
//

#include "stdafx.h"
#include "Dr52.h"

#include "Dr52Doc.h"
#include "Dr52View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr52View

IMPLEMENT_DYNCREATE(CDr52View, CFormView)

BEGIN_MESSAGE_MAP(CDr52View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr52View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr52View �R���X�g���N�V����/�f�X�g���N�V����

CDr52View::CDr52View()
	: CFormView(CDr52View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr52View::~CDr52View()
{
}

void CDr52View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr52View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr52View �f�f

#ifdef _DEBUG
void CDr52View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr52View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr52Doc* CDr52View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr52Doc)));
	return (CDr52Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr52View ���b�Z�[�W �n���h��
/*
 * ---------------------------------
 *      �O���t�̒T���i���D��j     *
 * ---------------------------------
 */

#include "mfcform.h"

#define N 8                                 /* �_�̐� */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* �אڍs�� */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,1,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,0,0,0,0},
                 {0,0,1,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                             /* �K��t���O */

int queue[100];             /* �L���[ */
int head,                   /* �擪�f�[�^�̃C���f�b�N�X */
    tail;                   /* �I�[�f�[�^�̃C���f�b�N�X */


void CDr52View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,j,p;
	tinit();cls();
    for (p=1;p<=N;p++){
        for (i=1;i<=N;i++)
            v[i]=0;
        head=tail=0;
        queue[tail++]=p;v[p]=1;
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
    }
	tfin();
}
