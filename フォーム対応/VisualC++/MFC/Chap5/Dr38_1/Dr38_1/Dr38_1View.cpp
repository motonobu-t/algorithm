// Dr38_1View.cpp : CDr38_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr38_1.h"

#include "Dr38_1Doc.h"
#include "Dr38_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr38_1View

IMPLEMENT_DYNCREATE(CDr38_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr38_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr38_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr38_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr38_1View::CDr38_1View()
	: CFormView(CDr38_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr38_1View::~CDr38_1View()
{
}

void CDr38_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr38_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr38_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr38_1View �f�f

#ifdef _DEBUG
void CDr38_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr38_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr38_1Doc* CDr38_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr38_1Doc)));
	return (CDr38_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr38_1View ���b�Z�[�W �n���h��
/*
 * -------------------------------------------------
 *      �t�|�[�����h�L�@�i�������̏������܂ށj     *
 * -------------------------------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
int pri[256];                   /* �D�揇�ʕ\ */
int sp1,sp2;                    /* �X�^�b�N�E�|�C���^ */

void CDr38_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
    char *p="(a+b)*(c+d)";      /* �� */

    for (i=0;i<=255;i++)        /* �I�y�����h�̗D�揇�� */
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;
    pri['(']=0;

    stack[0]=0;pri[0]=-1;       /* �ԕ� */
    sp1=sp2=0;
    while  (*p!='\0'){
        if (*p=='(')            /* ( �̏��� */
            stack[++sp1]=*p;
        else if(*p==')'){       /* ) �̏��� */
            while (stack[sp1]!='(')
                polish[++sp2]=stack[sp1--];
            sp1--;
        }
        else {                  /* �I�y�����h�Ɖ��Z�q�̏��� */
            while (pri[*p]<=pri[stack[sp1]])
                polish[++sp2]=stack[sp1--];
            stack[++sp1]=*p;
        }
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
