// Dr40View.cpp : CDr40View �N���X�̎���
//

#include "stdafx.h"
#include "Dr40.h"

#include "Dr40Doc.h"
#include "Dr40View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr40View

IMPLEMENT_DYNCREATE(CDr40View, CFormView)

BEGIN_MESSAGE_MAP(CDr40View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr40View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr40View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr40View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr40View �R���X�g���N�V����/�f�X�g���N�V����

CDr40View::CDr40View()
	: CFormView(CDr40View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr40View::~CDr40View()
{
}

void CDr40View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr40View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr40View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr40View �f�f

#ifdef _DEBUG
void CDr40View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr40View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr40Doc* CDr40View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr40Doc)));
	return (CDr40Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr40View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------
 *      ���ȍĕҐ��T���i�P�O�Ɉڂ��j     *
 * -----------------------------------------
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
void CDr40View::OnBnClickedButton1()
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

void CDr40View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p,*old1,*old2,*q;
	char key[32];
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);

	p=head->pointer;
    old1=old2=head;
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            printf("%15s%15s\n",p->name,p->tel);
            if (p!=head->pointer){       /* �擪�łȂ��Ƃ��� */
                q=old1->pointer;         /* �P�O�ƌ���     */
                old1->pointer=p;
                old2->pointer=p->pointer;
                p->pointer=q;
            }
            break;
        }
        old1=old2;
        old2=p;
        p=p->pointer;
    }
	tfin();
}

void CDr40View::OnBnClickedButton3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	struct tfield *p;
	p=talloc();               /* �_�~�[�E�m�[�h */
    p->pointer=head;
    head=p;
}
