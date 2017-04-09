// Rei41View.cpp : CRei41View �N���X�̎���
//

#include "stdafx.h"
#include "Rei41.h"

#include "Rei41Doc.h"
#include "Rei41View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei41View

IMPLEMENT_DYNCREATE(CRei41View, CFormView)

BEGIN_MESSAGE_MAP(CRei41View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei41View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei41View::OnBnClickedButton2)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CRei41View �R���X�g���N�V����/�f�X�g���N�V����

CRei41View::CRei41View()
	: CFormView(CRei41View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei41View::~CRei41View()
{
}

void CRei41View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei41View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei41View �f�f

#ifdef _DEBUG
void CRei41View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei41View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei41Doc* CRei41View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei41Doc)));
	return (CRei41Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei41View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------------
 *      ���X�g��p�����n�b�V���i�擪�ɒǉ��j     *
 * -----------------------------------------------
 */

#include "mfcform.h"

#define TableSize 1000
#define ModSize   1000

struct tfield{
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];               /* �|�C���^�E�e�[�u�� */
int hash(char *s)    /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        /* �L���̈�̎擾 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CRei41View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
	n=hash(p->name);         /* �n�b�V���O */
    p->pointer=dat[n];       /* �擪�ɒǉ� */
    dat[n]=p;
}

void CRei41View::OnBnClickedButton2()
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

int CRei41View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �����ɓ���ȍ쐬�R�[�h��ǉ����Ă��������B
	int n;
	for (n=0;n<TableSize;n++)    /* �|�C���^�E�e�[�u���̏����� */
        dat[n]=NULL;
	return 0;
}
