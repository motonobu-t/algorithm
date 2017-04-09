// Dr63_4View.cpp : CDr63_4View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_4.h"

#include "Dr63_4Doc.h"
#include "Dr63_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_4View

IMPLEMENT_DYNCREATE(CDr63_4View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_4View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_4View::CDr63_4View()
	: CFormView(CDr63_4View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_4View::~CDr63_4View()
{
}

void CDr63_4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr63_4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_4View �f�f

#ifdef _DEBUG
void CDr63_4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_4Doc* CDr63_4View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_4Doc)));
	return (CDr63_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_4View ���b�Z�[�W �n���h��
/*
 * -------------------------
 *      �q���x���g�Ȑ�     *
 * -------------------------
 */

#include "mfcform.h"
void hilbert(int n,double l,double angle)
{
    if (n==0)
        return;
    turn(angle);hilbert(n-1,l,-angle);move(l);
    turn(-angle);hilbert(n-1,l,angle);move(l);
    hilbert(n-1,l,angle);turn(-angle);move(l);
    hilbert(n-1,l,-angle);turn(angle);
}

void CDr63_4View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n=4;         /* ���� */

    ginit(); cls();

    setpoint(200,100);
    hilbert(n,10,90);
}
