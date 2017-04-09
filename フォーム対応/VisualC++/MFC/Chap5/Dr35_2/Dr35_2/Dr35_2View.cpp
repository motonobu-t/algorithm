// Dr35_2View.cpp : CDr35_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr35_2.h"

#include "Dr35_2Doc.h"
#include "Dr35_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr35_2View

IMPLEMENT_DYNCREATE(CDr35_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr35_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr35_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr35_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr35_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr35_2View::CDr35_2View()
	: CFormView(CDr35_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr35_2View::~CDr35_2View()
{
}

void CDr35_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr35_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr35_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr35_2View �f�f

#ifdef _DEBUG
void CDr35_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr35_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr35_2Doc* CDr35_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr35_2Doc)));
	return (CDr35_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr35_2View ���b�Z�[�W �n���h��
/*
 * -----------------------------
 *      ���X�g�f�[�^�̒T��     *
 * -----------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} sentinel,*head=&sentinel;  // ������

struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CDr35_2View::OnBnClickedButton1()
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

void CDr35_2View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	char key[32];
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);
 
	strcpy(sentinel.name,key);      /* �ԕ��ɃL�[������ */
    p=head;
    while (strcmp(p->name,key)!=0)
        p=p->pointer;
	tinit();cls();
    if (p!=&sentinel)
        printf("%s %s\n",p->name,p->tel);
    else
        printf("������܂���\n");
	tfin();
}
