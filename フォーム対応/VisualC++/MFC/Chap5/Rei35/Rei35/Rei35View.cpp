// Rei35View.cpp : CRei35View �N���X�̎���
//

#include "stdafx.h"
#include "Rei35.h"

#include "Rei35Doc.h"
#include "Rei35View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei35View

IMPLEMENT_DYNCREATE(CRei35View, CFormView)

BEGIN_MESSAGE_MAP(CRei35View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei35View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei35View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CRei35View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CRei35View �R���X�g���N�V����/�f�X�g���N�V����

CRei35View::CRei35View()
	: CFormView(CRei35View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei35View::~CRei35View()
{
}

void CRei35View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CRei35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei35View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei35View �f�f

#ifdef _DEBUG
void CRei35View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei35View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei35Doc* CRei35View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei35Doc)));
	return (CRei35Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei35View ���b�Z�[�W �n���h��


/*
 * -------------------------------
 *      ���X�g�f�[�^�ւ̒ǉ�     *
 * -------------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head=NULL;  // �֐��̊O�Ő錾
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CRei35View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
	p->pointer=head;
    head=p;
}
void CRei35View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p,*n;
	char key[20]; 
	n=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,n->name);
	text2.GetWindowText(buf);
	stoc(buf,n->tel);
	text3.GetWindowText(buf);
	stoc(buf,key);

    p=head;
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            n->pointer=p->pointer;
            p->pointer=n;
            return;
        }
        p=p->pointer;
    }
	tinit();cls();
    printf("�L�[�f�[�^��������܂���\n");
	tfin();
}
void CRei35View::OnBnClickedButton3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	tinit();cls();
	p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	tfin();
}
