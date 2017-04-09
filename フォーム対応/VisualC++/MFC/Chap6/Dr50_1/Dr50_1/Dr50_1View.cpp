// Dr50_1View.cpp : CDr50_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr50_1.h"

#include "Dr50_1Doc.h"
#include "Dr50_1View.h"
#include "Input.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr50_1View

IMPLEMENT_DYNCREATE(CDr50_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr50_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr50_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr50_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr50_1View::CDr50_1View()
	: CFormView(CDr50_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr50_1View::~CDr50_1View()
{
}

void CDr50_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr50_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr50_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr50_1View �f�f

#ifdef _DEBUG
void CDr50_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr50_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr50_1Doc* CDr50_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr50_1Doc)));
	return (CDr50_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr50_1View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      ���^�����ƌ���؁i���I�\���j     *
 * ---------------------------------------
 */
struct tnode {
    struct tnode *left;  /* ���ւ̃|�C���^ */
    wchar_t node[30];      /* ���I���������蓖�Ă��s�����ߌŒ蒷�z�� */
    struct tnode *right; /* �E�ւ̃|�C���^ */
};
struct tnode *root;

struct tnode *talloc(void)            /* �L���̈�̎擾 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void CDr50_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tnode *p,*q1,*q2;
    int c;
	CInput dlg;  // ���͗p�_�C�A���O�{�b�N�X

    root=talloc();
	dlg.m_msg="�����m�[�h ? ";
	dlg.m_text="";
	dlg.DoModal();
	_tcscpy_s(root->node,dlg.m_text);  // CString->TCHAR
	root->left=root->right=NULL;
    do {
        p=root;                             /* �؂̃T�[�` */
        while (p->left!=NULL){
			c=AfxMessageBox(CString(p->node),MB_YESNO);
            if (c==IDYES)
                p=p->left;
            else
                p=p->right;
        }
		c=AfxMessageBox(CString("������")+CString(p->node)+CString("�ł��B�������ł��� y/n"),MB_YESNO);

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
}
