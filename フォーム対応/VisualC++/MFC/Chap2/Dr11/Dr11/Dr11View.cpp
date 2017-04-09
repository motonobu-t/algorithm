// Dr11View.cpp : CDr11View �N���X�̎���
//

#include "stdafx.h"
#include "Dr11.h"

#include "Dr11Doc.h"
#include "Dr11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr11View

IMPLEMENT_DYNCREATE(CDr11View, CFormView)

BEGIN_MESSAGE_MAP(CDr11View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr11View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr11View �R���X�g���N�V����/�f�X�g���N�V����

CDr11View::CDr11View()
	: CFormView(CDr11View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr11View::~CDr11View()
{
}

void CDr11View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr11View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr11View �f�f

#ifdef _DEBUG
void CDr11View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr11Doc* CDr11View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr11Doc)));
	return (CDr11Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr11View ���b�Z�[�W �n���h��
/*
 * -----------------------
 *      �j���[�g���@     *
 * -----------------------
 */

#include "mfcform.h"

#define f(x) ((x)*(x)*(x)-(x)+1)
#define g(x) (3*(x)*(x)-1)
#define EPS  1e-8               /* �ł��؂�덷 */
#define LIMIT 50                /* �ł��؂�� */

void CDr11View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double x=-2.0,dx;
    int k;
	tinit();cls();
    for (k=1;k<=LIMIT;k++) {
        dx=x;
        x=x-f(x)/g(x);
        if (fabs(x-dx)<fabs(dx)*EPS) {
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("�������Ȃ�\n");
	tfin();
}
