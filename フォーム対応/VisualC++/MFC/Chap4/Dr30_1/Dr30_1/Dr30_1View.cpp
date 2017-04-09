// Dr30_1View.cpp : CDr30_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr30_1.h"

#include "Dr30_1Doc.h"
#include "Dr30_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_1View

IMPLEMENT_DYNCREATE(CDr30_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr30_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr30_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr30_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr30_1View::CDr30_1View()
	: CFormView(CDr30_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr30_1View::~CDr30_1View()
{
}

void CDr30_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr30_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr30_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr30_1View �f�f

#ifdef _DEBUG
void CDr30_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr30_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr30_1Doc* CDr30_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr30_1Doc)));
	return (CDr30_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr30_1View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------------
 *      ���H�����ǂ�i�o�H���X�^�b�N�ɋL�^����j     *
 * ---------------------------------------------------
 */

#include "mfcform.h"

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* �ʉ߈ʒu������X�^�b�N */
int visit(int i,int j)
{
    int k;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;       /* �K��ʒu���X�^�b�N�ɐς� */

    if (i==Ei && j==Ej){            /* �o���ɓ��B�����Ƃ� */
        for (k=0;k<sp;k++)          /* �ʉߓ_�̕\�� */
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                            /* �o���ɓ��B���Ȃ��Ԗ��H�����܂悤 */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    sp--;                            /* �X�^�b�N����̂Ă� */
    return success;
}

void CDr30_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    sp=0;                       /* �X�^�b�N�E�|�C���^�̏����� */
    success=0;                  /* �E�o�ɐ����������������t���O */
    Si=1; Sj=1; Ei=5; Ej=5;     /* �����Əo���̈ʒu */
	tinit();cls();
    printf("\n���H�̒T��\n");
    if (visit(Si,Sj)==0)
        printf("�o���͌�����܂���ł���\n");
    printf("\n");
	tfin();
}
