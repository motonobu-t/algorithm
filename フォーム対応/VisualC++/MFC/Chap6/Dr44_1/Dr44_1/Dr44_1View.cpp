// Dr44_1View.cpp : CDr44_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr44_1.h"

#include "Dr44_1Doc.h"
#include "Dr44_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr44_1View

IMPLEMENT_DYNCREATE(CDr44_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr44_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr44_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr44_1View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr44_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr44_1View::CDr44_1View()
	: CFormView(CDr44_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr44_1View::~CDr44_1View()
{
}

void CDr44_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr44_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr44_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr44_1View �f�f

#ifdef _DEBUG
void CDr44_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr44_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr44_1Doc* CDr44_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr44_1Doc)));
	return (CDr44_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr44_1View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      �Q���T���؂̃T�[�`�i�ċA�Łj     *
 * ---------------------------------------
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
struct tnode *search(struct tnode *p,char *key)  /* �؂̃T�[�` */
{
    if (p==NULL || strcmp(key,p->name)==0)
        return p;
    if (strcmp(key,p->name)<0)
        return search(p->left,key);
    else
        return search(p->right,key);
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
void CDr44_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char key[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
    root=gentree(root,key);
}

void CDr44_1View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tnode *p;
	char key[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
	tinit();cls();
    if ((p=search(root,key))!=NULL)
        printf("%s ��������܂���\n",p->name);
    else
        printf("������܂���\n");
	tfin();
}
