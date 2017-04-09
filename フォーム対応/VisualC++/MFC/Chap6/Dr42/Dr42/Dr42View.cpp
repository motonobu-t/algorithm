// Dr42View.cpp : CDr42View �N���X�̎���
//

#include "stdafx.h"
#include "Dr42.h"

#include "Dr42Doc.h"
#include "Dr42View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr42View

IMPLEMENT_DYNCREATE(CDr42View, CFormView)

BEGIN_MESSAGE_MAP(CDr42View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr42View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr42View �R���X�g���N�V����/�f�X�g���N�V����

CDr42View::CDr42View()
	: CFormView(CDr42View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr42View::~CDr42View()
{
}

void CDr42View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr42View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr42View �f�f

#ifdef _DEBUG
void CDr42View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr42View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr42Doc* CDr42View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr42Doc)));
	return (CDr42Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr42View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *      �Q���T���؂ւ̃f�[�^�ǉ�     *
 * -----------------------------------
 */

#include "mfcform.h"

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* �������؂ւ̃|�C���^ */
    char name[12];
    int right;          /* �E�����؂ւ̃|�C���^ */
};

int sp=8;               /* �m�[�h�̊i�[���݈ʒu */
struct tnode a[MaxSize]={{  1,"Machilda",  2},
                         {  3,"Candy",  4},
                         {  5,"Rolla"   ,nil},
                         {nil,"Ann"  ,nil},
                         {  6,"Emy"     ,  7},
                         {nil,"Nancy",nil},
                         {nil,"Eluza"   ,nil},
                         {nil,"Lisa" ,nil}};

void CDr42View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char key[12];
    int p,old,i;

	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
    p=0;                                /* �؂̃T�[�` */
    while (p!=nil){
        old=p;
        if (strcmp(key,a[p].name)<=0)
            p=a[p].left;
        else
            p=a[p].right;
    }

    a[sp].left=a[sp].right=nil;         /* �V�����m�[�h�̐ڑ� */
    strcpy(a[sp].name,key);
    if (strcmp(key,a[old].name)<=0)
        a[old].left=sp;
    else
        a[old].right=sp;
    sp++;

	tinit();cls();
    for (i=0;i<sp;i++)                  /* �m�[�h�E�e�[�u���̕\�� */
        printf("%4d%12s%4d\n",a[i].left,a[i].name,a[i].right);
	tfin();
}
