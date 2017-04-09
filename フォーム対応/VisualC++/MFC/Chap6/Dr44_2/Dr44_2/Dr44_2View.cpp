// Dr44_2View.cpp : CDr44_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr44_2.h"

#include "Dr44_2Doc.h"
#include "Dr44_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr44_2View

IMPLEMENT_DYNCREATE(CDr44_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr44_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr44_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr44_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr44_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr44_2View::CDr44_2View()
	: CFormView(CDr44_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr44_2View::~CDr44_2View()
{
}

void CDr44_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr44_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr44_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr44_2View �f�f

#ifdef _DEBUG
void CDr44_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr44_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr44_2Doc* CDr44_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr44_2Doc)));
	return (CDr44_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr44_2View ���b�Z�[�W �n���h��
/*
 * -------------------------------------
 *      �Q���T���؂̍쐬�i�ċA�Łj     *
 * -------------------------------------
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
void gentree(struct tnode **p,char *w)  /* �؂̍쐬�̍ċA�葱�� */
{                                       /* �Q�Ƃɂ��ďo��     */
    if ((*p)==NULL){
        (*p)=talloc();
        strcpy((*p)->name,w);
        (*p)->left=(*p)->right=NULL;
    }
    else if(strcmp(w,(*p)->name)<0)
        gentree(&((*p)->left),w);
    else
        gentree(&((*p)->right),w);
}
void CDr44_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	gentree(&root,dat);
}

void CDr44_2View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tnode *p;
	p=root;
	tinit();cls();
    while (p!=NULL){
        printf("%s\n",p->name);
        p=p->left;
    }
	tfin();
}
