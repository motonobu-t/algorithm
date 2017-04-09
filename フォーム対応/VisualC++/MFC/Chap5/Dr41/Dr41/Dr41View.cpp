// Dr41View.cpp : CDr41View �N���X�̎���
//

#include "stdafx.h"
#include "Dr41.h"

#include "Dr41Doc.h"
#include "Dr41View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr41View

IMPLEMENT_DYNCREATE(CDr41View, CFormView)

BEGIN_MESSAGE_MAP(CDr41View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr41View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr41View::OnBnClickedButton2)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDr41View �R���X�g���N�V����/�f�X�g���N�V����

CDr41View::CDr41View()
	: CFormView(CDr41View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr41View::~CDr41View()
{
}

void CDr41View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr41View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr41View �f�f

#ifdef _DEBUG
void CDr41View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr41View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr41Doc* CDr41View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr41Doc)));
	return (CDr41Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr41View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------------
 *      ���X�g��p�����n�b�V���i�I�[�ɒǉ��j     *
 * -----------------------------------------------
 */

#include "mfcform.h"

#define TableSize 1000
#define ModSize   1000

struct tfield {
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];             /* �|�C���^�E�e�[�u�� */
int hash(char *s)         /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CDr41View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	struct tfield *p,*q;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);

	n=hash(p->name);
    if (dat[n]==NULL){            /* ��̂Ƃ� */
        dat[n]=p;
        p->pointer=NULL;
    }
    else {                        /* �����������Ƃ� */
        q=dat[n];
        while (q->pointer!=NULL)  /* �I�[�֒ǉ� */
            q=q->pointer;
        q->pointer=p;
        p->pointer=NULL;
    }
}

void CDr41View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	char key[32];
	struct tfield *p;
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);

	n=hash(key);
    p=dat[n];
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0)
            printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	tfin();
}

int CDr41View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �����ɓ���ȍ쐬�R�[�h��ǉ����Ă��������B
	int n;
	for (n=0;n<TableSize;n++)    /* �|�C���^�E�e�[�u���̏����� */
        dat[n]=NULL;

	return 0;
}
