// Rei43View.cpp : CRei43View �N���X�̎���
//

#include "stdafx.h"
#include "Rei43.h"

#include "Rei43Doc.h"
#include "Rei43View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei43View

IMPLEMENT_DYNCREATE(CRei43View, CFormView)

BEGIN_MESSAGE_MAP(CRei43View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei43View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei43View �R���X�g���N�V����/�f�X�g���N�V����

CRei43View::CRei43View()
	: CFormView(CRei43View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei43View::~CRei43View()
{
}

void CRei43View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei43View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei43View �f�f

#ifdef _DEBUG
void CRei43View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei43View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei43Doc* CRei43View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei43Doc)));
	return (CRei43Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei43View ���b�Z�[�W �n���h��
/*
 * ---------------------------
 *      �Q���T���؂̍쐬     *
 * ---------------------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
} *root;
int flag=0;

struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void CRei43View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tnode *p,*old;
	char dat[12];
	CString buf;

	if (flag==0){
		root=talloc();                  /* ���[�g�E�m�[�h */
		text1.GetWindowText(buf);
		stoc(buf,root->name);
	    root->left=root->right=NULL;
		flag=1;
	}
	else {
		text1.GetWindowText(buf);
		stoc(buf,dat);
        p=root;                     /* �؂̃T�[�` */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* �V�����m�[�h�̐ڑ� */
        strcpy(p->name,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }
	tinit();cls();
	printf("���̎q\n");
	p=root;
	do {
		printf("%s\n",p->name);
		p=p->left;
	}while (p!=NULL);
	printf("�E�̎q\n");
	p=root;
	do {
		printf("%s\n",p->name);
		p=p->right;
	}while (p!=NULL);
	tfin();
}
