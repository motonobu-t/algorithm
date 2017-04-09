// Dr46View.cpp : CDr46View �N���X�̎���
//

#include "stdafx.h"
#include "Dr46.h"

#include "Dr46Doc.h"
#include "Dr46View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr46View

IMPLEMENT_DYNCREATE(CDr46View, CFormView)

BEGIN_MESSAGE_MAP(CDr46View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr46View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr46View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr46View �R���X�g���N�V����/�f�X�g���N�V����

CDr46View::CDr46View()
	: CFormView(CDr46View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr46View::~CDr46View()
{
}

void CDr46View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr46View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr46View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr46View �f�f

#ifdef _DEBUG
void CDr46View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr46View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr46Doc* CDr46View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr46Doc)));
	return (CDr46Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr46View ���b�Z�[�W �n���h��
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
    struct connect {            /* �ڑ��֌W�������\���� */
        struct tnode *node;     /* �q�m�[�h */
        char *parent;           /* �e�̖��O */
        char direct;            /* �e�̍��̎q���E�̎q�������� */
    } q[128],w[128];
    int i,child,n,level;

    child=1; level=0;           /* �����l */
    q[0].node=p; q[0].parent="root"; q[0].direct=' ';
    do {
        n=0;
        printf("level %d :\n",level);
        for (i=0;i<child;i++){
            printf("%12s->%c:%12s\n",q[i].parent,q[i].direct,q[i].node->name);
            /* �P���̃��x���̎q�ւ̃|�C���^���X�^�b�N�ɐς� */
            if (q[i].node->left!=NULL){
                w[n].parent=q[i].node->name;
                w[n].direct='l';
                w[n].node=q[i].node->left;
                n++;
            }
            if (q[i].node->right!=NULL){
                w[n].parent=q[i].node->name;
                w[n].direct='r';
                w[n].node=q[i].node->right;
                n++;
            }
        }
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
void CDr46View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
    root=gentree(root,dat);
}

void CDr46View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	treewalk(root);
	tfin();
}
