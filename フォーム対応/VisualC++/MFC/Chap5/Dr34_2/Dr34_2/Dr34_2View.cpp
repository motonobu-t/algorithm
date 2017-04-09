// Dr34_2View.cpp : CDr34_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr34_2.h"

#include "Dr34_2Doc.h"
#include "Dr34_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr34_2View

IMPLEMENT_DYNCREATE(CDr34_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr34_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr34_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr34_2View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr34_2View::OnBnClickedButton3)
//	ON_WM_ACTIVATE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDr34_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr34_2View::CDr34_2View()
	: CFormView(CDr34_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr34_2View::~CDr34_2View()
{
}

void CDr34_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CDr34_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr34_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr34_2View �f�f

#ifdef _DEBUG
void CDr34_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr34_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr34_2Doc* CDr34_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr34_2Doc)));
	return (CDr34_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr34_2View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------------
 *      ���X�g�f�[�^�̍쐬�i�_�~�[�E�m�[�h�j     *
 * -----------------------------------------------
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

void CDr34_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	CString buf;
	p=talloc();
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
	old->pointer=p;
    old=p;
}

void CDr34_2View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    old->pointer=NULL;
}

void CDr34_2View::OnBnClickedButton3()
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

int CDr34_2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �����ɓ���ȍ쐬�R�[�h��ǉ����Ă��������B
	head=talloc();      /* �_�~�[�E�m�[�h�̍쐬 */
	old=head;

	return 0;
}
