// Dr29View.cpp : CDr29View �N���X�̎���
//

#include "stdafx.h"
#include "Dr29.h"

#include "Dr29Doc.h"
#include "Dr29View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr29View

IMPLEMENT_DYNCREATE(CDr29View, CFormView)

BEGIN_MESSAGE_MAP(CDr29View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr29View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr29View �R���X�g���N�V����/�f�X�g���N�V����

CDr29View::CDr29View()
	: CFormView(CDr29View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr29View::~CDr29View()
{
}

void CDr29View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr29View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr29View �f�f

#ifdef _DEBUG
void CDr29View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr29View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr29Doc* CDr29View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr29Doc)));
	return (CDr29Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr29View ���b�Z�[�W �n���h��
/*
 * ------------------------------------------
 *      �n�m�C�̓��i�������P���炷�j      *
 * ------------------------------------------
 */

#include "mfcform.h"

#define Total 'a'+'b'+'c'
void hanoi(int n,char a,char b)  /* �ċA�葱 */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d�Ԃ̉~�Ղ� %c ���� %c �Ɉړ�\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}

void CDr29View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
    hanoi(n,'a','b');
	tfin();
}
