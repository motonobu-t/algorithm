// Dr25View.cpp : CDr25View �N���X�̎���
//

#include "stdafx.h"
#include "Dr25.h"

#include "Dr25Doc.h"
#include "Dr25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr25View

IMPLEMENT_DYNCREATE(CDr25View, CFormView)

BEGIN_MESSAGE_MAP(CDr25View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr25View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr25View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr25View �R���X�g���N�V����/�f�X�g���N�V����

CDr25View::CDr25View()
	: CFormView(CDr25View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr25View::~CDr25View()
{
}

void CDr25View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr25View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr25View �f�f

#ifdef _DEBUG
void CDr25View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr25View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr25Doc* CDr25View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr25Doc)));
	return (CDr25Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr25View ���b�Z�[�W �n���h��
/*
 * -------------------
 *      �n�b�V��     *
 * -------------------
 */

#include "mfcform.h"

#define TableSize 1050
#define ModSize      1000
struct tel{             /* �f�[�^�E�e�[�u�� */
    char name[12];
    char telnum[12];
    int empty;
} dat[TableSize];
int hash(char *s)        /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}

void CDr25View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n;
    char a[12],b[12];
	tinit();cls();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,a);
	text2.GetWindowText(buf);
	stoc(buf,b);

    n=hash(a);
    while (dat[n].empty==1 && n<TableSize)
        n++;
    if (n<TableSize){
        strcpy(dat[n].name,a);   // �x���G���[�̏ꍇ��strcpy�̑����strcpy_s���g��
        strcpy(dat[n].telnum,b);
        dat[n].empty=1;
    }
    else
        printf("�\����t�ł�\n");
	tfin();
}

void CDr25View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	char a[12];
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,a);
	tinit();cls();
	n=hash(a);
    while (strcmp(a,dat[n].name)!=0 && n<TableSize)
        n++;
    if (n<TableSize)
        printf("%15s%15s\n",dat[n].name,dat[n].telnum);
    else
        printf("�f�|�^�͌�����܂���ł���\n");
	tfin();
}
