// Dr66View.cpp : CDr66View �N���X�̎���
//

#include "stdafx.h"
#include "Dr66.h"

#include "Dr66Doc.h"
#include "Dr66View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66View

IMPLEMENT_DYNCREATE(CDr66View, CFormView)

BEGIN_MESSAGE_MAP(CDr66View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr66View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr66View �R���X�g���N�V����/�f�X�g���N�V����

CDr66View::CDr66View()
	: CFormView(CDr66View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr66View::~CDr66View()
{
}

void CDr66View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr66View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr66View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr66View �f�f

#ifdef _DEBUG
void CDr66View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr66View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr66Doc* CDr66View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr66Doc)));
	return (CDr66Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr66View ���b�Z�[�W �n���h��
/*
 * -------------------------
 *      �R�m�����̖��     *
 * -------------------------
 */

#include "mfcform.h"

void backtrack(int,int);

#define N 5

int m[N+4][N+4],                    /* �Ֆ� */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* �R�m�̈ړ������� */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* �R�m�̈ړ������� */

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* �K�⏇�Ԃ̋L�^ */
        if (count==N*N){
            printf("��%d\n",++num);    /* ���̕\�� */
            for (i=2;i<=N+1;i++){
                for (j=2;j<=N+1;j++)
                    printf("%4d",m[i][j]);
                printf("\n");
            }
			AfxMessageBox(CString("���̈ړ�"),MB_OK); // ���̈ړ��܂ő҂�
			cls();
        }
        else
            for (k=0;k<8;k++)           /* �i�ވʒu��I�� */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* �P�O�ɖ߂� */
        count--;
    }
}

void CDr66View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* �Ֆ� */
            else
                m[i][j]=1;      /* �� */
	tinit();cls();
    backtrack(2,2);
	tfin();
}
