// Rei25View.cpp : CRei25View �N���X�̎���
//

#include "stdafx.h"
#include "Rei25.h"

#include "Rei25Doc.h"
#include "Rei25View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei25View

IMPLEMENT_DYNCREATE(CRei25View, CFormView)

BEGIN_MESSAGE_MAP(CRei25View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei25View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei25View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei25View �R���X�g���N�V����/�f�X�g���N�V����

CRei25View::CRei25View()
	: CFormView(CRei25View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei25View::~CRei25View()
{
}

void CRei25View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CRei25View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei25View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei25View �f�f

#ifdef _DEBUG
void CRei25View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei25View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei25Doc* CRei25View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei25Doc)));
	return (CRei25Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei25View ���b�Z�[�W �n���h��
/*
 * -------------------
 *      �n�b�V��     *
 * -------------------
 */

#include "mfcform.h"

#define TableSize 1000
#define ModSize   1000

struct tel{             /* �f�[�^�E�e�[�u�� */
    char name[12];
    char telnum[12];
} dat[TableSize];

int hash(char *s)    /* �n�b�V���֐� */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
void CRei25View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n;
    char a[12],b[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,a);
	text2.GetWindowText(buf);
	stoc(buf,b);

    n=hash(a);
    strcpy(dat[n].name,a);   // �x���G���[�̏ꍇ��strcpy�̑����strcpy_s���g��
    strcpy(dat[n].telnum,b);
}

void CRei25View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	char a[12];
	tinit();cls();
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,a);

	n=hash(a);
    printf("%15s%15s\n",dat[n].name,dat[n].telnum);
	tfin();
}
