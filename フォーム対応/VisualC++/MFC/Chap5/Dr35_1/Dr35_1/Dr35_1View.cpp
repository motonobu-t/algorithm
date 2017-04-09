// Dr35_1View.cpp : CDr35_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr35_1.h"

#include "Dr35_1Doc.h"
#include "Dr35_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr35_1View

IMPLEMENT_DYNCREATE(CDr35_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr35_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr35_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr35_1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr35_1View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr35_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr35_1View::CDr35_1View()
	: CFormView(CDr35_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr35_1View::~CDr35_1View()
{
}

void CDr35_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr35_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr35_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr35_1View �f�f

#ifdef _DEBUG
void CDr35_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr35_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr35_1Doc* CDr35_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr35_1Doc)));
	return (CDr35_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr35_1View ���b�Z�[�W �n���h��
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
} *head=NULL;  // ����������
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CDr35_1View::OnBnClickedButton1()
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

void CDr35_1View::OnBnClickedButton2()
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
    printf("%s ��������Ȃ��̂Ő擪�ɒǉ����܂�\n",key);
	tfin();
	n->pointer=head;
    head=n;
}

void CDr35_1View::OnBnClickedButton3()
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
