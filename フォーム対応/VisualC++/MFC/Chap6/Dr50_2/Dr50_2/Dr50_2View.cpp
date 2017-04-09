// Dr50_2View.cpp : CDr50_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr50_2.h"

#include "Dr50_2Doc.h"
#include "Dr50_2View.h"
#include "Input.h"
#include <wchar.h>
#include <locale.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr50_2View

IMPLEMENT_DYNCREATE(CDr50_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr50_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr50_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr50_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr50_2View::CDr50_2View()
	: CFormView(CDr50_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr50_2View::~CDr50_2View()
{
}

void CDr50_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr50_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr50_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr50_2View �f�f

#ifdef _DEBUG
void CDr50_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr50_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr50_2Doc* CDr50_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr50_2Doc)));
	return (CDr50_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr50_2View ���b�Z�[�W �n���h��
/*
 * -------------------------------------------
 *      �؁i���I�\���j�̃f�B�X�N�ւ̕ۑ�     *
 * -------------------------------------------
 */

struct tnode {
    struct tnode *left;  /* ���ւ̃|�C���^ */
    wchar_t node[30];      /* ���I���������蓖�Ă��s�����ߌŒ蒷�z�� */
    struct tnode *right; /* �E�ւ̃|�C���^ */
};
struct tnode *root;
#define Rec 34L         /* ���R�[�h�E�T�C�Y */
#define Leaf -1         /* �t */
FILE *fp;

struct tnode *talloc(void)            /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *readtree(struct tnode *p)    /* �t�@�C������؂����[�h */
{
    int flag;
    p=talloc();
    fwscanf(fp,L"%30ls%4d",p->node,&flag);
    if (flag==Leaf)
        p->left=p->right=NULL;
    else{
        p->left=readtree(p->left);
        p->right=readtree(p->right);
    }
    return p;
}
void writetree(struct tnode *p)      /* �t�@�C���ɖ؂����C�g */
{
    if (p!=NULL){
        if (p->left==NULL)
            fwprintf(fp,L"%30ls%4d",p->node,Leaf);
        else
            fwprintf(fp,L"%30ls%4d",p->node,!Leaf);
        writetree(p->left);
        writetree(p->right);
    }
}
void CDr50_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tnode *p,*q1,*q2;
    int c;
	CInput dlg;  // ���͗p�_�C�A���O�{�b�N�X

	setlocale(LC_ALL,"");
	if ((fp=fopen("dbase.dat","r"))==NULL){
        root=talloc();
		dlg.m_msg="�����m�[�h ? ";
		dlg.m_text="";
		dlg.DoModal();
		_tcscpy_s(root->node,dlg.m_text);
		root->left=root->right=NULL;
    }
    else {
        root=readtree(root);
        fclose(fp);
    }
	do {
        p=root;                             /* �؂̃T�[�` */
        while (p->left!=NULL){
			c=AfxMessageBox(CString(p->node),MB_YESNO);
            if (c==IDYES)
                p=p->left;
            else
                p=p->right;
        }
		c=AfxMessageBox(CString("������")+CString(p->node)+CString("�ł�"),MB_YESNO);

        if (c==IDNO){                         /* �w�K�@�\ */
            q1=talloc(); *q1=*p;        /* �m�[�h�̈ړ� */

            q2=talloc();                /* �V�����m�[�h�̍쐬 */
			dlg.m_msg="���Ȃ��̍l����";
			dlg.m_text="";
			dlg.DoModal();
			_tcscpy_s(q2->node,dlg.m_text);
            q2->left=q2->right=NULL;
                                        /* ����m�[�h�̍쐬 */
			dlg.m_msg=q1->node+CString("��")+q2->node+CString("����ʂ��鎿���");
			dlg.m_text="";
			dlg.DoModal();
			_tcscpy_s(p->node,dlg.m_text);
			c=AfxMessageBox(CString("�������̍��ڂ�")+q1->node+CString("�ŗǂ��ł���"),MB_YESNO);


            if (c==IDYES){      /* �q�̐ڑ� */
                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
    } while (c=AfxMessageBox(CString("�����܂���"),MB_YESNO),c==IDYES);
    if ((fp=fopen("dbase.dat","w"))!=NULL){
        writetree(root);
        fclose(fp);
    }
}
