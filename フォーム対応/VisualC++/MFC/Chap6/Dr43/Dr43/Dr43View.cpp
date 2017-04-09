// Dr43View.cpp : CDr43View �N���X�̎���
//

#include "stdafx.h"
#include "Dr43.h"

#include "Dr43Doc.h"
#include "Dr43View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr43View

IMPLEMENT_DYNCREATE(CDr43View, CFormView)

BEGIN_MESSAGE_MAP(CDr43View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr43View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr43View �R���X�g���N�V����/�f�X�g���N�V����

CDr43View::CDr43View()
	: CFormView(CDr43View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr43View::~CDr43View()
{
}

void CDr43View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr43View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr43View �f�f

#ifdef _DEBUG
void CDr43View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr43View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr43Doc* CDr43View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr43Doc)));
	return (CDr43Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr43View ���b�Z�[�W �n���h��
/*
 * ---------------------------
 *      �ŏ��m�[�h�̒T��     *
 * ---------------------------
 */

#include "mfcform.h"
struct tnode {
    struct tnode *left;     /* �������؂ւ̃|�C���^ */
    char name[12];          /* ���O */
    struct tnode *right;    /* �E�����؂ւ̃|�C���^ */
} *root;
int flag=0;  // �{�^���̍ŏ��̃N���b�N�𔻒�
struct tnode *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void CDr43View::OnBnClickedButton1()
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
	p=root;                    /* �ŏ��m�[�h�̒T�� */
    while (p->left!=NULL)
        p=p->left;
    printf("�ŏ��m�[�h�� %s\n",p->name);

    p=root;                    /* �ő�m�[�h�̒T�� */
    while (p->right!=NULL)
        p=p->right;
    printf("�ő�m�[�h�� %s\n",p->name);
	tfin();
}
