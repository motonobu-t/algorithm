// Rei9View.cpp : CRei9View �N���X�̎���
//

#include "stdafx.h"
#include "Rei9.h"

#include "Rei9Doc.h"
#include "Rei9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei9View

IMPLEMENT_DYNCREATE(CRei9View, CFormView)

BEGIN_MESSAGE_MAP(CRei9View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei9View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei9View �R���X�g���N�V����/�f�X�g���N�V����

CRei9View::CRei9View()
	: CFormView(CRei9View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei9View::~CRei9View()
{
}

void CRei9View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei9View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei9View �f�f

#ifdef _DEBUG
void CRei9View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei9View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei9Doc* CRei9View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei9Doc)));
	return (CRei9Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei9View ���b�Z�[�W �n���h��

/*
 * ----------------------------
 *     ��`���ɂ���ϕ�     *
 * ----------------------------
 */

#include "mfcform.h"

#define f(x) (sqrt(4-(x)*(x)))   /* ��ϕ��֐� */

void CRei9View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int k;
    double a,b,n,h,x,s,sum;
	CString buf;
	text1.GetWindowText(buf);
	a=stod(buf);
	text2.GetWindowText(buf);
	b=stod(buf);

    n=50;             /* ���`���Ԃ̕����� */
    h=(b-a)/n;        /* ��ԕ� */
    x=a; s=0;
    for (k=1;k<=n-1;k++){
        x=x+h;
        s=s+f(x);
    }
    sum=h*((f(a)+f(b))/2+s);

	tinit();cls();
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
    printf("   /%f\n",a);
	tfin();
}
