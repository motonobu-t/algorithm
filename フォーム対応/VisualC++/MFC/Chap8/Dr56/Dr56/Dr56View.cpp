// Dr56View.cpp : CDr56View �N���X�̎���
//

#include "stdafx.h"
#include "Dr56.h"

#include "Dr56Doc.h"
#include "Dr56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr56View

IMPLEMENT_DYNCREATE(CDr56View, CFormView)

BEGIN_MESSAGE_MAP(CDr56View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr56View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr56View �R���X�g���N�V����/�f�X�g���N�V����

CDr56View::CDr56View()
	: CFormView(CDr56View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr56View::~CDr56View()
{
}

void CDr56View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr56View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr56View �f�f

#ifdef _DEBUG
void CDr56View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr56View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr56Doc* CDr56View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr56Doc)));
	return (CDr56Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr56View ���b�Z�[�W �n���h��
/*
 * ----------------------
 *      �Q�����͗l      *
 * ----------------------
 */

#include "mfcform.h"

void CDr56View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double leng=200.0,    /* �ӂ̏����l */
           angle=89.0,    /* ��]�p */
           step=1.0;      /* �ӂ̌����l */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}
