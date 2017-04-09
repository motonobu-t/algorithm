// Dr9View.cpp : CDr9View �N���X�̎���
//

#include "stdafx.h"
#include "Dr9.h"

#include "Dr9Doc.h"
#include "Dr9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr9View

IMPLEMENT_DYNCREATE(CDr9View, CFormView)

BEGIN_MESSAGE_MAP(CDr9View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr9View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr9View �R���X�g���N�V����/�f�X�g���N�V����

CDr9View::CDr9View()
	: CFormView(CDr9View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr9View::~CDr9View()
{
}

void CDr9View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr9View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr9View �f�f

#ifdef _DEBUG
void CDr9View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr9View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr9Doc* CDr9View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr9Doc)));
	return (CDr9Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr9View ���b�Z�[�W �n���h��
/*
 * -----------------------------
 *      �V���v�\���̒�ϕ�     *
 * -----------------------------
 */

#include "mfcform.h"

#define f(x) (sqrt(4-(x)*(x)))   /* ��ϕ��֐� */

void CDr9View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int k;
    double a,b,n,h,fo,fe,sum;

	CString buf;
	text1.GetWindowText(buf);
	a=stod(buf);
	text2.GetWindowText(buf);
	b=stod(buf);

    n=50;              /* ���`���Ԃ̕����� */
    h=(b-a)/(2*n);     /* ��ԕ� */
    fo=0; fe=0;
    for (k=1;k<=2*n-3;k=k+2){
        fo=fo+f(a+h*k);         /* ����̘a */
        fe=fe+f(a+h*(k+1));     /* �������̘a */
    }
    sum=(f(a)+f(b)+4*(fo+f(b-h))+2*fe)*h/3;

	tinit();cls();
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
    printf("   /%f\n",a);
	tfin();
}
