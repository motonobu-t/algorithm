// Dr63_2View.cpp : CDr63_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_2.h"

#include "Dr63_2Doc.h"
#include "Dr63_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_2View

IMPLEMENT_DYNCREATE(CDr63_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_2View::CDr63_2View()
	: CFormView(CDr63_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_2View::~CDr63_2View()
{
}

void CDr63_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr63_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_2View �f�f

#ifdef _DEBUG
void CDr63_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_2Doc* CDr63_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_2Doc)));
	return (CDr63_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_2View ���b�Z�[�W �n���h��
/*
 * -----------------
 *      �b�Ȑ�     *
 * -----------------
 */

#include "mfcform.h"
void ccurve(int n)
{
    if (n==0){
        move(5);
    }
    else {
        ccurve(n-1);
        turn(90);
        ccurve(n-1);
        turn(-90);
    }
}

void CDr63_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n=10;       /* ���� */

    ginit(); cls();

    setpoint(200,100);
    ccurve(n);
}
