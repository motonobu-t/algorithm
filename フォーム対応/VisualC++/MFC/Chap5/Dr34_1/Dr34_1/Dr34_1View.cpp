// Dr34_1View.cpp : CDr34_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr34_1.h"

#include "Dr34_1Doc.h"
#include "Dr34_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr34_1View

IMPLEMENT_DYNCREATE(CDr34_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr34_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr34_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr34_1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr34_1View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr34_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr34_1View::CDr34_1View()
	: CFormView(CDr34_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr34_1View::~CDr34_1View()
{
}

void CDr34_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CDr34_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr34_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr34_1View �f�f

#ifdef _DEBUG
void CDr34_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr34_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr34_1Doc* CDr34_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr34_1Doc)));
	return (CDr34_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr34_1View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      ���X�g�f�[�^�̍쐬�i���͏��j     *
 * ---------------------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head,*old;    // �֐��̊O�Ő錾
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

 
int flag=0;  // �o�^�{�^������P��ڂɉ����ꂽ���̔���t���O

void CDr34_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p; 
	CString buf;
	if (flag==0){
	    head=talloc();
		text1.GetWindowText(buf);
		stoc(buf,head->name);
		text2.GetWindowText(buf);
		stoc(buf,head->tel);
		old=head;
		flag=1;
	}
	else {
		p=talloc();
		text1.GetWindowText(buf);
		stoc(buf,p->name);
		text2.GetWindowText(buf);
		stoc(buf,p->tel);
        old->pointer=p;
        old=p;
    }
}

void CDr34_1View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    old->pointer=NULL;
	flag=0;
}

void CDr34_1View::OnBnClickedButton3()
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
