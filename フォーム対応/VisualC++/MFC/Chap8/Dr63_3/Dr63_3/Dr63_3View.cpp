// Dr63_3View.cpp : CDr63_3View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_3.h"

#include "Dr63_3Doc.h"
#include "Dr63_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_3View

IMPLEMENT_DYNCREATE(CDr63_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_3View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_3View::CDr63_3View()
	: CFormView(CDr63_3View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_3View::~CDr63_3View()
{
}

void CDr63_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr63_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_3View �f�f

#ifdef _DEBUG
void CDr63_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_3Doc* CDr63_3View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_3Doc)));
	return (CDr63_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_3View ���b�Z�[�W �n���h��
/*
 * ---------------------------
 *      �h���S���E�J�[�u     *
 * ---------------------------
 */

#include "mfcform.h"
void dragon(int n,double a)
{
    if (n==0){
        move(5);
    }
    else {
        dragon(n-1,90);
        turn(a);
        dragon(n-1,-90);
    }
}

void CDr63_3View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n=10;       /* ���� */

    ginit(); cls();

    setpoint(200,100);
    dragon(n,90);
}
