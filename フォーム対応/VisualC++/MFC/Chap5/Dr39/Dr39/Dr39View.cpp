// Dr39View.cpp : CDr39View �N���X�̎���
//

#include "stdafx.h"
#include "Dr39.h"

#include "Dr39Doc.h"
#include "Dr39View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr39View

IMPLEMENT_DYNCREATE(CDr39View, CFormView)

BEGIN_MESSAGE_MAP(CDr39View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr39View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr39View �R���X�g���N�V����/�f�X�g���N�V����

CDr39View::CDr39View()
	: CFormView(CDr39View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr39View::~CDr39View()
{
}

void CDr39View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr39View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr39View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr39View �f�f

#ifdef _DEBUG
void CDr39View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr39View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr39Doc* CDr39View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr39Doc)));
	return (CDr39Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr39View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      �D�揇�ʃp�[�W���O�i���ږ@�j     *
 * ---------------------------------------
 */

#include "mfcform.h"

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

double v[50];        /* �v�Z�p�X�^�b�N */
char ope[50];        /* ���Z�q�p�X�^�b�N */
int pri[256];        /* �D�揇�ʕ\ */
int sp1,sp2;         /* �X�^�b�N�E�|�C���^ */

void calc(void)             /* ���Z���� */
{
    switch (ope[sp1]) {
        case '|' : v[sp2-1]=(v[sp2-1]+v[sp2])/2;break;
        case '>' : v[sp2-1]=Max(v[sp2-1],v[sp2]);break;
        case '<' : v[sp2-1]=Min(v[sp2-1],v[sp2]);break;
    }
    sp2--; sp1--;
}

void CDr39View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char *expression="(1>2|2<8|3<4)|(9<2)",*p=expression;

    pri['|']=1; pri['<']=pri['>']=2;
    pri['(']=3; pri[')']=0;

    ope[0]=0; pri[0]=-1;        /* �ԕ� */
    sp1=sp2=0;
    while  (*p!='\0'){
        if ('0'<=*p && *p<='9')
            v[++sp2]=*p-'0';
        else {
            while (pri[*p]<=pri[ope[sp1]] && ope[sp1]!='(')
                calc();
            if (*p!=')')
                ope[++sp1]=*p;
            else
                sp1--;      /* �i����菜�� */
        }
        p++;
    }
    while (sp1>0)           /* ���Z�q�X�^�b�N����ɂȂ�܂� */
        calc();
	tinit();cls();
    printf("%s=%f\n",expression,v[1]);
	tfin();
}
