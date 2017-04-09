// Rei44View.cpp : CRei44View �N���X�̎���
//

#include "stdafx.h"
#include "Rei44.h"

#include "Rei44Doc.h"
#include "Rei44View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei44View

IMPLEMENT_DYNCREATE(CRei44View, CFormView)

BEGIN_MESSAGE_MAP(CRei44View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei44View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei44View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei44View �R���X�g���N�V����/�f�X�g���N�V����

CRei44View::CRei44View()
	: CFormView(CRei44View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei44View::~CRei44View()
{
}

void CRei44View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei44View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei44View �f�f

#ifdef _DEBUG
void CRei44View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei44View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei44Doc* CRei44View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei44Doc)));
	return (CRei44Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei44View ���b�Z�[�W �n���h��
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


void CRei44View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
    root=gentree(root,dat);
}

void CRei44View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tnode *p;
	p=root;
	tinit();cls();
	while (p!=NULL) {
		printf("%s\n",p->name);
		p=p->left;
	}
	tfin();
}
