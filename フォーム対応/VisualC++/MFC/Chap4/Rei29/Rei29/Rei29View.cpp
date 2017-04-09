// Rei29View.cpp : CRei29View �N���X�̎���
//

#include "stdafx.h"
#include "Rei29.h"

#include "Rei29Doc.h"
#include "Rei29View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei29View

IMPLEMENT_DYNCREATE(CRei29View, CFormView)

BEGIN_MESSAGE_MAP(CRei29View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei29View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei29View �R���X�g���N�V����/�f�X�g���N�V����

CRei29View::CRei29View()
	: CFormView(CRei29View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei29View::~CRei29View()
{
}

void CRei29View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei29View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei29View �f�f

#ifdef _DEBUG
void CRei29View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei29View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei29Doc* CRei29View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei29Doc)));
	return (CRei29Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei29View ���b�Z�[�W �n���h��
/*
 * ------------------------------
 *      �n�m�C�̓��̍ċA��      *
 * ------------------------------
 */

#include "mfcform.h"
void hanoi(int n,char a,char b,char c)  /* �ċA�葱 */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d�Ԃ̉~�Ղ� %c ���� %c �Ɉړ�\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void CRei29View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
    hanoi(n,'a','b','c');
	tfin();
}
