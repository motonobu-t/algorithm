// rei54View.cpp : Crei54View �N���X�̎���
//

#include "stdafx.h"
#include "rei54.h"

#include "rei54Doc.h"
#include "rei54View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei54View

IMPLEMENT_DYNCREATE(Crei54View, CFormView)

BEGIN_MESSAGE_MAP(Crei54View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Crei54View::OnBnClickedButton1)
END_MESSAGE_MAP()

// Crei54View �R���X�g���N�V����/�f�X�g���N�V����

Crei54View::Crei54View()
	: CFormView(Crei54View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

Crei54View::~Crei54View()
{
}

void Crei54View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL Crei54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void Crei54View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Crei54View �f�f

#ifdef _DEBUG
void Crei54View::AssertValid() const
{
	CFormView::AssertValid();
}

void Crei54View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Crei54Doc* Crei54View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crei54Doc)));
	return (Crei54Doc*)m_pDocument;
}
#endif //_DEBUG


// Crei54View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      �d���������̈�M����     *
 * -------------------------------
 */

#include "mfcform.h"

#define Node 4        /* �ߓ_�̐� */
#define Root 6        /* �ӂ̐� */
#define Start 1       /* �J�n�_ */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,1},
                       {0,1,0,1,2},
                       {0,0,1,0,1},
                       {0,1,2,1,0}};
int success,
    v[Root+1],      /* �o�H������X�^�b�N */
    n;              /* �ʉ߂������̐� */
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){    /* �ӂ̐������ʉ߂����ɖ߂����� */
        printf("�� %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--; a[j][i]--;    /* �ʂ�����؂藣�� */
                n--;
                visit(j);
                a[i][j]++; a[j][i]++;    /* ���𕜋����� */
                n++;
            }
    }
}

void Crei54View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("���Ȃ�\n");
	tfin();
}
