// Rei37View.cpp : CRei37View �N���X�̎���
//

#include "stdafx.h"
#include "Rei37.h"

#include "Rei37Doc.h"
#include "Rei37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei37View

IMPLEMENT_DYNCREATE(CRei37View, CFormView)

BEGIN_MESSAGE_MAP(CRei37View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei37View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei37View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei37View �R���X�g���N�V����/�f�X�g���N�V����

CRei37View::CRei37View()
	: CFormView(CRei37View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei37View::~CRei37View()
{
}

void CRei37View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CRei37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei37View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei37View �f�f

#ifdef _DEBUG
void CRei37View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei37View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei37Doc* CRei37View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei37Doc)));
	return (CRei37Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei37View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *      �o�������X�g�f�[�^�̍쐬     *
 * -----------------------------------
 */

#include "mfcform.h"

struct tfield {
    struct tfield *left;    /* �t�|�C���^ */
    char name[20];          /* ���O       */
    char tel[20];           /* �d�b�ԍ�   */
    struct tfield *right;   /* ���|�C���^ */
} *head,*tail=NULL;

struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CRei37View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
	p->left=tail;
    tail=p;
}

void CRei37View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=tail;                 /* �����X�g�̍쐬 */
    head=NULL;
    while (p!=NULL){
        p->right=head;
        head=p;
        p=p->left;
    }

	tinit();cls();
    printf("���������X�g\n");
    p=head;                 /* ���X�g�̏��\�� */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("�t�������X�g\n");
    p=tail;                 /* ���X�g�̋t�\�� */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	tfin();
}
