// Rei39View.cpp : CRei39View �N���X�̎���
//

#include "stdafx.h"
#include "Rei39.h"

#include "Rei39Doc.h"
#include "Rei39View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei39View

IMPLEMENT_DYNCREATE(CRei39View, CFormView)

BEGIN_MESSAGE_MAP(CRei39View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei39View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei39View �R���X�g���N�V����/�f�X�g���N�V����

CRei39View::CRei39View()
	: CFormView(CRei39View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei39View::~CRei39View()
{
}

void CRei39View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei39View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei39View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei39View �f�f

#ifdef _DEBUG
void CRei39View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei39View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei39Doc* CRei39View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei39Doc)));
	return (CRei39Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei39View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------------
 *      �D�揇�ʃp�[�W���O�i�t�|�[�����h�ɕϊ��j     *
 * ---------------------------------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
double v[50];
int pri[256];           /* �D�揇�ʕ\ */
int sp1,sp2;            /* �X�^�b�N�E�|�C���^ */

void CRei39View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
    char *p="(6+3)/(6-2)+3*2^3-1",*expression=p;  /* �� */

    for (i=0;i<=255;i++)
        pri[i]=4;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2; pri['^']=3;
    pri['(']=5; pri[')']=0;

    stack[0]=0;pri[0]=-1;        /* �ԕ� */
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

    sp1=0;                     /* ���̌v�Z */
    for (i=1;i<=sp2;i++){
        if ('0'<=polish[i] && polish[i]<='9')
            v[++sp1]=polish[i]-'0';
        else {
            switch (polish[i]){
                case '+':v[sp1-1]=v[sp1-1]+v[sp1];break;
                case '-':v[sp1-1]=v[sp1-1]-v[sp1];break;
                case '*':v[sp1-1]=v[sp1-1]*v[sp1];break;
                case '/':v[sp1-1]=v[sp1-1]/v[sp1];break;
                case '^':v[sp1-1]=pow(v[sp1-1],v[sp1]);break;
            }
            sp1--;
        }
    }
	tinit();cls();
    printf("%s=%f\n",expression,v[1]);
	tfin();
}
