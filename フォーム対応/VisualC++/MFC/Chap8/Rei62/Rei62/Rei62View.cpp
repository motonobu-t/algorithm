// Rei62View.cpp : CRei62View �N���X�̎���
//

#include "stdafx.h"
#include "Rei62.h"

#include "Rei62Doc.h"
#include "Rei62View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei62View

IMPLEMENT_DYNCREATE(CRei62View, CFormView)

BEGIN_MESSAGE_MAP(CRei62View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei62View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei62View �R���X�g���N�V����/�f�X�g���N�V����

CRei62View::CRei62View()
	: CFormView(CRei62View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei62View::~CRei62View()
{
}

void CRei62View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei62View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei62View �f�f

#ifdef _DEBUG
void CRei62View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei62View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei62Doc* CRei62View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei62Doc)));
	return (CRei62Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei62View ���b�Z�[�W �n���h��
/*
 * -----------------------
 *       �R�b�z�Ȑ�      *
 * -----------------------
 */

#include "mfcform.h"
void koch(int n,double leng)        /* �R�b�z�Ȑ��̍ċA�葱�� */
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}

void CRei62View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int    n=4;         /* �R�b�z���� */
    double leng=4.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

    koch(n,leng);
}
