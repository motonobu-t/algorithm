// Rei46View.cpp : CRei46View �N���X�̎���
//

#include "stdafx.h"
#include "Rei46.h"

#include "Rei46Doc.h"
#include "Rei46View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei46View

IMPLEMENT_DYNCREATE(CRei46View, CFormView)

BEGIN_MESSAGE_MAP(CRei46View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei46View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei46View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei46View �R���X�g���N�V����/�f�X�g���N�V����

CRei46View::CRei46View()
	: CFormView(CRei46View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei46View::~CRei46View()
{
}

void CRei46View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei46View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei46View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei46View �f�f

#ifdef _DEBUG
void CRei46View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei46View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei46Doc* CRei46View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei46Doc)));
	return (CRei46Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei46View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------------
 *      ���x�����Ƃ̂Q���T���؂̃g���o�[�T��     *
 * -----------------------------------------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
} *root=NULL;

struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void treewalk(struct tnode *p)  /* ���x�����Ƃ̖؂̃g���o�[�T�� */
{
    struct tnode *q[128],       /* �|�C���^�E�e�[�u�� */
                 *w[128];       /* ��Ɨp */
    int i,child,n,level;

    child=1; q[0]=p; level=0;   /* �����l */
    do {
        n=0;
        printf("level %d :",level);
        for (i=0;i<child;i++){
            printf("%12s",q[i]->name); /* �m�[�h�̕\�� */
            /* �P���̃��x���̎q�ւ̃|�C���^���X�^�b�N�ɐς� */
            if (q[i]->left!=NULL)
                w[n++]=q[i]->left;
            if (q[i]->right!=NULL)
                w[n++]=q[i]->right;
        }
        printf("\n");
        child=n;            /* �P���̃��x���̎q�̐� */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}
struct tnode *gentree(struct tnode *p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}
void CRei46View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	root=gentree(root,dat);
}

void CRei46View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	treewalk(root);
	tfin();
}
