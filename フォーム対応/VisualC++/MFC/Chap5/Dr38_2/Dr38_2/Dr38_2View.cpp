// Dr38_2View.cpp : CDr38_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr38_2.h"

#include "Dr38_2Doc.h"
#include "Dr38_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr38_2View

IMPLEMENT_DYNCREATE(CDr38_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr38_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr38_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr38_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr38_2View::CDr38_2View()
	: CFormView(CDr38_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr38_2View::~CDr38_2View()
{
}

void CDr38_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr38_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr38_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr38_2View �f�f

#ifdef _DEBUG
void CDr38_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr38_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr38_2Doc* CDr38_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr38_2Doc)));
	return (CDr38_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr38_2View ���b�Z�[�W �n���h��
/*
 * -------------------------------------------------
 *      �t�|�[�����h�L�@�i�������̏������܂ށj     *
 * -------------------------------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
int pri[256];                   /* �D�揇�ʕ\ */
int sp1,sp2;                    /* �X�^�b�N�E�|�C���^ */

void CDr38_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
    char *p="(a+b)*(c+d)";      /* �� */

    for (i=0;i<=255;i++)        /* �I�y�����h�̗D�揇�� */
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;    /* ���Z�q�̗D�揇�� */
    pri['(']=4; pri[')']=0;

    stack[0]=0;pri[0]=-1;       /* �ԕ� */
    sp1=sp2=0;
    while  (*p!='\0'){
        while (pri[*p]<=pri[stack[sp1]] && stack[sp1]!='(')
            polish[++sp2]=stack[sp1--];
        if (*p!=')')
            stack[++sp1]=*p;
        else
            sp1--;
        p++;

    }
    for (i=sp1;i>0;i--)        /* �X�^�b�N�̎c������o�� */
        polish[++sp2]=stack[i];
	tinit();cls();
    for (i=1;i<=sp2;i++)       /* �t�|�[�����h���̕\�� */
        putchar(polish[i]);
    printf("\n");
	tfin();
}
