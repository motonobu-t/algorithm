// Dr63_1View.cpp : CDr63_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_1.h"

#include "Dr63_1Doc.h"
#include "Dr63_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_1View

IMPLEMENT_DYNCREATE(CDr63_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_1View::CDr63_1View()
	: CFormView(CDr63_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_1View::~CDr63_1View()
{
}

void CDr63_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr63_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_1View �f�f

#ifdef _DEBUG
void CDr63_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_1Doc* CDr63_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_1Doc)));
	return (CDr63_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_1View ���b�Z�[�W �n���h��
/*
 * --------------------------
 *       ���؋Ȑ����̂Q     *
 * --------------------------
 */

#include "mfcform.h"
void ctree(int n,double x0,double y0,double leng,double angle)
                                  /* ���؋Ȑ��̍ċA�葱�� */
{
    double rd=3.14159/180;
    int k;

    if (n==0)
        return;

    setpoint(x0,y0);setangle(angle);
    for (k=1;k<=4;k++){        /* �����`��`�� */
        turn(90);
        move(leng);
    }

    ctree(n-1,x0+leng*cos((angle-45)*rd)/sqrt(2.0),  /* �E������ */
              y0+leng*sin((angle-45)*rd)/sqrt(2.0),
              leng/sqrt(2.0),angle-45);
    ctree(n-1,x0+sqrt(2.0)*leng*cos((angle+45)*rd),  /* �������� */
              y0+sqrt(2.0)*leng*sin((angle+45)*rd),
              leng/sqrt(2.0),angle+45);
}

void CDr63_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int    n=9;               /* �}�̎��� */
    double x0=0.0,y0=50.0,    /* ���̈ʒu */
           leng=100.0,        /* �}�̒��� */
           angle=90.0;        /* �}�̌��� */

    ginit(); cls();
    window(-640,-400,640,400);

    ctree(n,x0,y0,leng,angle);    /* �ċA�Ăяo�� */
}
