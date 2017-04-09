// Dr37View.cpp : CDr37View �N���X�̎���
//

#include "stdafx.h"
#include "Dr37.h"

#include "Dr37Doc.h"
#include "Dr37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr37View

IMPLEMENT_DYNCREATE(CDr37View, CFormView)

BEGIN_MESSAGE_MAP(CDr37View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr37View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr37View::OnBnClickedButton2)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDr37View �R���X�g���N�V����/�f�X�g���N�V����

CDr37View::CDr37View()
	: CFormView(CDr37View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr37View::~CDr37View()
{
}

void CDr37View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr37View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr37View �f�f

#ifdef _DEBUG
void CDr37View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr37View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr37Doc* CDr37View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr37Doc)));
	return (CDr37Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr37View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------
 *      �z�E�o�������X�g�f�[�^�̍쐬     *
 * -----------------------------------------
 */

#include "mfcform.h"

struct tfield {
    struct tfield *left;    /* �t�|�C���^ */
    char name[20];          /* ���O       */
    char tel[20];           /* �d�b�ԍ�   */
    struct tfield *right;   /* ���|�C���^ */
} *head;  // �֐��̊O�Ő錾
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CDr37View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
    p->right=head;
    p->left=head->left;
    head->left->right=p;
    head->left=p;
}

void CDr37View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	tinit();cls();
	printf("���������X�g\n");
    p=head->right;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }
    printf("�t�������X�g\n");
    p=head->left;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	tfin();
}

int CDr37View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �����ɓ���ȍ쐬�R�[�h��ǉ����Ă��������B
	head=talloc();                  /* �_�~�[�E�m�[�h�̍쐬 */
	head->left=head->right=head;

	return 0;
}
