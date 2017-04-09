// Dr5View.cpp : CDr5View �N���X�̎���
//

#include "stdafx.h"
#include "Dr5.h"

#include "Dr5Doc.h"
#include "Dr5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr5View

IMPLEMENT_DYNCREATE(CDr5View, CFormView)

BEGIN_MESSAGE_MAP(CDr5View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr5View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr5View �R���X�g���N�V����/�f�X�g���N�V����

CDr5View::CDr5View()
	: CFormView(CDr5View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr5View::~CDr5View()
{
}

void CDr5View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr5View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr5View �f�f

#ifdef _DEBUG
void CDr5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr5Doc* CDr5View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr5Doc)));
	return (CDr5Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr5View ���b�Z�[�W �n���h��
/*
 * --------------------------------------
 *     �����e�J�����@�ɂ��ʐς̌v�Z   *
 * --------------------------------------
 */

#include "mfcform.h"

#define NUM 1000
double rnd(void)
{
    return (double)rand()/(RAND_MAX+0.1);
}

void CDr5View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double x,y,s;
    int i,in=0;
    for (i=0;i<NUM;i++){
        x=2*rnd();
        y=rnd();
        if (x*x/4+y*y<=1)
            in++;
    }
    s=4.0*(2.0*in/NUM);

	tinit();cls();
    printf("�ȉ~�̖ʐ�=%f\n",s);
	tfin();
}
