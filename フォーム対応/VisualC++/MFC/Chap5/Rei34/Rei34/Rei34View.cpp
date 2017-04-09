// Rei34View.cpp : CRei34View �N���X�̎���
//

#include "stdafx.h"
#include "Rei34.h"

#include "Rei34Doc.h"
#include "Rei34View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei34View

IMPLEMENT_DYNCREATE(CRei34View, CFormView)

BEGIN_MESSAGE_MAP(CRei34View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei34View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei34View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei34View �R���X�g���N�V����/�f�X�g���N�V����

CRei34View::CRei34View()
	: CFormView(CRei34View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei34View::~CRei34View()
{
}

void CRei34View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CRei34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei34View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei34View �f�f

#ifdef _DEBUG
void CRei34View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei34View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei34Doc* CRei34View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei34Doc)));
	return (CRei34Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei34View ���b�Z�[�W �n���h��
/*
 * -----------------------------
 *      ���X�g�f�[�^�̍쐬     *
 * -----------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* ���O */
    char tel[20];              /* �d�b�ԍ� */
    struct tfield *pointer;    /* ���̃f�[�^�ւ̃|�C���^ */
} *head=NULL;  // �֐��̊O�Ő錾��������
struct tfield *talloc(void)     /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CRei34View::OnBnClickedButton1()
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

void CRei34View::OnBnClickedButton2()
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
