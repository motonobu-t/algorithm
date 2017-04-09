// Rei36View.cpp : CRei36View �N���X�̎���
//

#include "stdafx.h"
#include "Rei36.h"

#include "Rei36Doc.h"
#include "Rei36View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei36View

IMPLEMENT_DYNCREATE(CRei36View, CFormView)

BEGIN_MESSAGE_MAP(CRei36View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei36View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei36View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRei36View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CRei36View �R���X�g���N�V����/�f�X�g���N�V����

CRei36View::CRei36View()
	: CFormView(CRei36View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei36View::~CRei36View()
{
}

void CRei36View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CRei36View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei36View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei36View �f�f

#ifdef _DEBUG
void CRei36View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei36View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei36Doc* CRei36View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei36Doc)));
	return (CRei36Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei36View ���b�Z�[�W �n���h��
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
void CRei36View::OnBnClickedButton1()
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

void CRei36View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p,*old;
	char key[20];
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);

	p=old=head;
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            if (p==head)
                head=p->pointer;
            else
                old->pointer=p->pointer;
            return;
        }
        old=p;
        p=p->pointer;
    }
	tinit();cls();
    printf("�L�[�f�[�^��������܂���\n");
	tfin();
}

void CRei36View::OnBnClickedButton3()
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
