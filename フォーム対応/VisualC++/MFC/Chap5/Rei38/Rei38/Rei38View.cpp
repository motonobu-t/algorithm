// Rei38View.cpp : CRei38View �N���X�̎���
//

#include "stdafx.h"
#include "Rei38.h"

#include "Rei38Doc.h"
#include "Rei38View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei38View

IMPLEMENT_DYNCREATE(CRei38View, CFormView)

BEGIN_MESSAGE_MAP(CRei38View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei38View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei38View �R���X�g���N�V����/�f�X�g���N�V����

CRei38View::CRei38View()
	: CFormView(CRei38View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei38View::~CRei38View()
{
}

void CRei38View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei38View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei38View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei38View �f�f

#ifdef _DEBUG
void CRei38View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei38View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei38Doc* CRei38View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei38Doc)));
	return (CRei38Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei38View ���b�Z�[�W �n���h��
/*
 * ---------------------------
 *      �t�|�[�����h�L�@     *
 * ---------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
int pri[256];                   /* �D�揇�ʕ\ */
int sp1,sp2;                    /* �X�^�b�N�E�|�C���^ */

void CRei38View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
    char *p="a+b-c*d/e";        /* �� */

	for (i=0;i<=255;i++)        /* �D�揇�ʕ\�̍쐬 */
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;

    stack[0]=0;pri[0]=-1;       /* �ԕ� */
    sp1=sp2=0;
    while  (*p!='\0'){
        while (pri[*p]<=pri[stack[sp1]])
            polish[++sp2]=stack[sp1--];
        stack[++sp1]=*p++;
    }
    for (i=sp1;i>0;i--)         /* �X�^�b�N�̎c������o�� */
        polish[++sp2]=stack[i];

	tinit();cls();
    for (i=1;i<=sp2;i++)
        putchar(polish[i]);
    printf("\n");
	tfin();
}
