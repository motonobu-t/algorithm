// Dr26_4View.cpp : CDr26_4View �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_4.h"

#include "Dr26_4Doc.h"
#include "Dr26_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_4View

IMPLEMENT_DYNCREATE(CDr26_4View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_4View �R���X�g���N�V����/�f�X�g���N�V����

CDr26_4View::CDr26_4View()
	: CFormView(CDr26_4View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr26_4View::~CDr26_4View()
{
}

void CDr26_4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CDr26_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr26_4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_4View �f�f

#ifdef _DEBUG
void CDr26_4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_4Doc* CDr26_4View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_4Doc)));
	return (CDr26_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_4View ���b�Z�[�W �n���h��
/*
 * ------------------------------------------
 *      ���[�N���b�h�̌ݏ��@�i�ċA�Łj      *
 * ------------------------------------------
 */

#include "mfcform.h"
int gcd(int m,int n)
{
    if (m==n)
        return m;
    if (m>n)
        return gcd(m-n,n);
    else
        return gcd(m,n-m);
}
void CDr26_4View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a,b;

	CString buf;
	text1.GetWindowText(buf);
	a=stoi(buf);
	text2.GetWindowText(buf);
	b=stoi(buf);

	tinit();cls();	
    printf("�ő����=%d\n",gcd(a,b));
	tfin();
}
