// Dr49View.cpp : CDr49View �N���X�̎���
//

#include "stdafx.h"
#include "Dr49.h"

#include "Dr49Doc.h"
#include "Dr49View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr49View

IMPLEMENT_DYNCREATE(CDr49View, CFormView)

BEGIN_MESSAGE_MAP(CDr49View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr49View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr49View �R���X�g���N�V����/�f�X�g���N�V����

CDr49View::CDr49View()
	: CFormView(CDr49View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr49View::~CDr49View()
{
}

void CDr49View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr49View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr49View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr49View �f�f

#ifdef _DEBUG
void CDr49View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr49View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr49Doc* CDr49View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr49Doc)));
	return (CDr49Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr49View ���b�Z�[�W �n���h��
/*
 * ---------------------------------
 *      ���̖؂�p�������̌v�Z     *
 * ---------------------------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    int ope;                /* ���� */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
};
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* ���̖؂̍쐬 */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* ������̏I�[���m�[�h�ɂ��� */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* �萔�̂Ƃ��͐��l�ɕϊ� */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* �I�[������ */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void postfix(struct tnode *p)    /* ���̖؂̌v�Z */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        switch (p->ope){
            case '+': p->ope=(p->left->ope)+(p->right->ope);break;
            case '-': p->ope=(p->left->ope)-(p->right->ope);break;
            case '*': p->ope=(p->left->ope)*(p->right->ope);break;
            case '/': p->ope=(p->left->ope)/(p->right->ope);break;
        }
    }
}
void CDr49View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct tnode *root;
    char expression[]="53*64+2/-";
    root=NULL;
    root=gentree(root,expression);
	tinit();cls();
    postfix(root);         /* ���̌v�Z */
    printf("value=%d\n",root->ope);
	tfin();
}
