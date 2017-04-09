// Dr45_2View.cpp : CDr45_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr45_2.h"

#include "Dr45_2Doc.h"
#include "Dr45_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr45_2View

IMPLEMENT_DYNCREATE(CDr45_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr45_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr45_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr45_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr45_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr45_2View::CDr45_2View()
	: CFormView(CDr45_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr45_2View::~CDr45_2View()
{
}

void CDr45_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr45_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr45_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr45_2View �f�f

#ifdef _DEBUG
void CDr45_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr45_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr45_2Doc* CDr45_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr45_2Doc)));
	return (CDr45_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr45_2View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------------
 *      �Q���T���؂̃g���o�[�T���i��ċA�Łj     *
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
void treewalk(struct tnode *p)   /* �؂̃g���o�[�T���i��ċA�Łj */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)){
        while (q!=NULL){         /* �s���邾�����ɐi�� */
            w[sp++]=q;           /* �e�̈ʒu���X�^�b�N�ɐς� */
            q=q->left;
        }
        sp--;                    /* �P�O�̐e�ɖ߂� */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* �E�֐i�� */
    }
}
struct tnode *gentree(struct tnode *p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(p->name,w)<0)
        p->right=gentree(p->right,w);
    else
        p->left=gentree(p->left,w);
    return p;
}

void CDr45_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
    root=gentree(root,dat);
}

void CDr45_2View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	treewalk(root);
	tfin();
}
