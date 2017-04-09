// Rei45View.cpp : CRei45View �N���X�̎���
//

#include "stdafx.h"
#include "Rei45.h"

#include "Rei45Doc.h"
#include "Rei45View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei45View

IMPLEMENT_DYNCREATE(CRei45View, CFormView)

BEGIN_MESSAGE_MAP(CRei45View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei45View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei45View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei45View �R���X�g���N�V����/�f�X�g���N�V����

CRei45View::CRei45View()
	: CFormView(CRei45View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei45View::~CRei45View()
{
}

void CRei45View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei45View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei45View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei45View �f�f

#ifdef _DEBUG
void CRei45View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei45View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei45Doc* CRei45View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei45Doc)));
	return (CRei45Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei45View ���b�Z�[�W �n���h��
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
        treewalk(p->left);
        printf("%s\n",p->name);
        treewalk(p->right);
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

void CRei45View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	root=gentree(root,dat);
}

void CRei45View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	treewalk(root);
	tfin();
}
