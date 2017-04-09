// Dr30_2View.cpp : CDr30_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr30_2.h"

#include "Dr30_2Doc.h"
#include "Dr30_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_2View

IMPLEMENT_DYNCREATE(CDr30_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr30_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr30_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr30_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr30_2View::CDr30_2View()
	: CFormView(CDr30_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr30_2View::~CDr30_2View()
{
}

void CDr30_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr30_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr30_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr30_2View �f�f

#ifdef _DEBUG
void CDr30_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr30_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr30_2Doc* CDr30_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr30_2Doc)));
	return (CDr30_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr30_2View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      ���ׂĂ̖��H�����ǂ�     *
 * -------------------------------
 */

#include "mfcform.h"

int m[9][9]={{2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* �ʉ߈ʒu������X�^�b�N */
int visit(int i,int j)
{
    int k;
    static int path=1;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;   /* �K��ʒu���X�^�b�N�ɐς� */

    if (i==Ei && j==Ej){        /* �o���ɓ��B�����Ƃ� */
		printf("\n");    // printf("\n�E�E�E)�͒P�Ƃ̉��s�ɕύX
        printf("path=%d\n",path++);     /* �ʉߓ_�̕\�� */
        for (k=0;k<sp;k++)
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                                /* ���H�����܂悤 */
    if (m[i][j+1]==0) visit(i,j+1);
    if (m[i+1][j]==0) visit(i+1,j);
    if (m[i][j-1]==0) visit(i,j-1);
    if (m[i-1][j]==0) visit(i-1,j);

    sp--;                       /* �X�^�b�N����̂Ă� */
    m[i][j]=0;                  /* �ʂȌo�H�̒T���̂��� */

    return success;
}

void CDr30_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    sp=0;                       /* �X�^�b�N�E�|�C���^�̏����� */
    success=0;                  /* �E�o�ɐ����������������t���O */
    Si=1; Sj=1; Ei=7; Ej=7;     /* �����Əo���̈ʒu */
	tinit();cls();
    printf("\n���H�̒T��");
    if (visit(Si,Sj)==0)
        printf("�o���͌�����܂���ł���\n");
    printf("\n");
	tfin();
}
