// Dr36View.cpp : CDr36View �N���X�̎���
//

#include "stdafx.h"
#include "Dr36.h"

#include "Dr36Doc.h"
#include "Dr36View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr36View

IMPLEMENT_DYNCREATE(CDr36View, CFormView)

BEGIN_MESSAGE_MAP(CDr36View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr36View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr36View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr36View::OnBnClickedButton3)
//	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_BUTTON4, &CDr36View::OnBnClickedButton4)
END_MESSAGE_MAP()

// CDr36View �R���X�g���N�V����/�f�X�g���N�V����

CDr36View::CDr36View()
	: CFormView(CDr36View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr36View::~CDr36View()
{
}

void CDr36View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr36View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr36View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr36View �f�f

#ifdef _DEBUG
void CDr36View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr36View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr36Doc* CDr36View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr36Doc)));
	return (CDr36Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr36View ���b�Z�[�W �n���h��
/*
 * -----------------------------
 *      ���X�g�f�[�^�̍폜     *
 * -----------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head=NULL;
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CDr36View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=talloc();
    p->pointer=head;
    head=p;
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
}

void CDr36View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	char key[20];
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);
	p=head;
    while (p->pointer!=NULL){
        if (strcmp(key,p->pointer->name)==0){
            p->pointer=p->pointer->pointer;
            return;
        }
        p=p->pointer;
    }
	tinit();cls();
    printf("�L�[�f�[�^��������܂���\n");
	tfin();
}

void CDr36View::OnBnClickedButton3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	tinit();cls();
	p=head->pointer;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	tfin();
}

void CDr36View::OnBnClickedButton4()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=talloc();
	p->pointer=head;
	head=p;
}
