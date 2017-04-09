// Rei49View.cpp : CRei49View �N���X�̎���
//

#include "stdafx.h"
#include "Rei49.h"

#include "Rei49Doc.h"
#include "Rei49View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei49View

IMPLEMENT_DYNCREATE(CRei49View, CFormView)

BEGIN_MESSAGE_MAP(CRei49View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei49View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei49View �R���X�g���N�V����/�f�X�g���N�V����

CRei49View::CRei49View()
	: CFormView(CRei49View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei49View::~CRei49View()
{
}

void CRei49View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei49View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei49View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei49View �f�f

#ifdef _DEBUG
void CRei49View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei49View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei49Doc* CRei49View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei49Doc)));
	return (CRei49Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei49View ���b�Z�[�W �n���h��
/*
 * -----------------
 *      ���̖�     *
 * -----------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char ope;               /* ���� */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};

struct tnode *talloc(void)       /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* ���̖؂̍쐬 */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* ������̏I�[���m�[�h�ɂ��� */
    w[n-1]='\0';           /* �I�[������ */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void prefix(struct tnode *p)     /* �ړ��` */
{
    if (p!=NULL){
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}
void infix(struct tnode *p)      /* �}���` */
{
    if (p!=NULL){
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}
void postfix(struct tnode *p)    /* �ڔ��` */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}
void CRei49View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct tnode *root;
    char expression[]="ab*cd+e/-";
    root=NULL;
    root=gentree(root,expression);
	tinit();cls();
    printf("prefix  = ");prefix(root);        /* ���̖؂̑��� */
	printf("\n");  // ���s��P�Ə�����
	printf("infix   = ");infix(root);
	printf("\n");
	printf("postfix = ");postfix(root);
    printf("\n");
	tfin();
}
