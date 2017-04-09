// Dr62_1View.cpp : CDr62_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr62_1.h"

#include "Dr62_1Doc.h"
#include "Dr62_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_1View

IMPLEMENT_DYNCREATE(CDr62_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr62_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr62_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr62_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr62_1View::CDr62_1View()
	: CFormView(CDr62_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr62_1View::~CDr62_1View()
{
}

void CDr62_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr62_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr62_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr62_1View �f�f

#ifdef _DEBUG
void CDr62_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr62_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr62_1Doc* CDr62_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr62_1Doc)));
	return (CDr62_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr62_1View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *       �R�b�z��      *
 * ---------------------
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

void CDr62_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int    i,
           n=4;         /* �R�b�z���� */
    double leng=4.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(150,300);
    setangle(0);
    for (i=0;i<3;i++){
          koch(n,leng);
        turn(-120);
    }
}
