// Dr45_1View.cpp : CDr45_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr45_1.h"

#include "Dr45_1Doc.h"
#include "Dr45_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr45_1View

IMPLEMENT_DYNCREATE(CDr45_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr45_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr45_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr45_1View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr45_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr45_1View::CDr45_1View()
	: CFormView(CDr45_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr45_1View::~CDr45_1View()
{
}

void CDr45_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr45_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr45_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr45_1View �f�f

#ifdef _DEBUG
void CDr45_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr45_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr45_1Doc* CDr45_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr45_1Doc)));
	return (CDr45_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr45_1View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *      �Q���T���؂̃g���o�[�T��     *
 * -----------------------------------
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
void treewalk(struct tnode *p)  /* �؂̃g���o�[�T�� */
{
    if (p!=NULL){
        treewalk(p->right);
        printf("%s\n",p->name);
        treewalk(p->left);
    }
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

void CDr45_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	root=gentree(root,dat);
}

void CDr45_1View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	treewalk(root);
	tfin();
}
