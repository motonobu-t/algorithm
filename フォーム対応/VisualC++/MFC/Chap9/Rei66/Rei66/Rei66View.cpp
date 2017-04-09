// Rei66View.cpp : CRei66View �N���X�̎���
//

#include "stdafx.h"
#include "Rei66.h"

#include "Rei66Doc.h"
#include "Rei66View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66View

IMPLEMENT_DYNCREATE(CRei66View, CFormView)

BEGIN_MESSAGE_MAP(CRei66View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei66View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei66View �R���X�g���N�V����/�f�X�g���N�V����

CRei66View::CRei66View()
	: CFormView(CRei66View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei66View::~CRei66View()
{
}

void CRei66View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei66View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei66View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei66View �f�f

#ifdef _DEBUG
void CRei66View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei66View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei66Doc* CRei66View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei66Doc)));
	return (CRei66Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei66View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------
 *      �����܁i�W�p�����������j�̖��     *
 * -----------------------------------------
 */

#include "mfcform.h"

#define N 8
int column[N+1],    /* �������ɉ��܂��u����Ă��邩��\��*/
    rup[2*N+1],     /* �E�オ��̑Ίp����ɒu����Ă��邩��\�� */
    lup[2*N+1],     /* ���オ��̑Ίp����ɒu����Ă��邩��\�� */
    queen[N+1];     /* ���܂̈ʒu */

void backtrack(int i)
{
    int j,x,y;
    static int num=0;
    if (i>N){
        printf("�� %d \n",++num);        /* ���̕\�� */
        for (y=1;y<=N;y++){
            for (x=1;x<=N;x++)
                if (queen[y]==x)
                    printf(" Q");
                else
                    printf(" .");
            printf("\n");
        }
		AfxMessageBox(CString("���̈ړ�"),MB_OK);  // ���̈ړ��܂ő҂�
		cls();
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                /* �i���C���j�����܂̈ʒu */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* �ǖʂ̕ύX */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* �ǖʂ̖߂� */
            }
        }
    }
}

void CRei66View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
	tinit();cls();
    backtrack(1);
	tfin();
}
