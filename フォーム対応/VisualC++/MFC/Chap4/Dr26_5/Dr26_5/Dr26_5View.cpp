// Dr26_5View.cpp : CDr26_5View �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_5.h"

#include "Dr26_5Doc.h"
#include "Dr26_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_5View

IMPLEMENT_DYNCREATE(CDr26_5View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_5View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_5View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_5View �R���X�g���N�V����/�f�X�g���N�V����

CDr26_5View::CDr26_5View()
	: CFormView(CDr26_5View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr26_5View::~CDr26_5View()
{
}

void CDr26_5View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CDr26_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr26_5View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_5View �f�f

#ifdef _DEBUG
void CDr26_5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_5Doc* CDr26_5View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_5Doc)));
	return (CDr26_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_5View ���b�Z�[�W �n���h��
/*
 * ------------------------------------------
 *      ���[�N���b�h�̌ݏ��@�i�ċA�Łj      *
 * ------------------------------------------
 */

#include "mfcform.h"

int gcd(int m,int n)
{
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}
void CDr26_5View::OnBnClickedButton1()
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
