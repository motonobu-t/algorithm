// Rei11View.cpp : CRei11View �N���X�̎���
//

#include "stdafx.h"
#include "Rei11.h"

#include "Rei11Doc.h"
#include "Rei11View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei11View

IMPLEMENT_DYNCREATE(CRei11View, CFormView)

BEGIN_MESSAGE_MAP(CRei11View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei11View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei11View �R���X�g���N�V����/�f�X�g���N�V����

CRei11View::CRei11View()
	: CFormView(CRei11View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei11View::~CRei11View()
{
}

void CRei11View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei11View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei11View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei11View �f�f

#ifdef _DEBUG
void CRei11View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei11View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei11Doc* CRei11View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei11Doc)));
	return (CRei11Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei11View ���b�Z�[�W �n���h��
/*
 * -----------------
 *      �Q���@     *
 * -----------------
 */

#include "mfcform.h"

#define f(x) ((x)*(x)*(x)-(x)+1)
#define EPS 1e-8                /* �ł��؂�덷 */
#define LIMIT 50                /* �ł��؂�� */

void CRei11View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double low,high,x;
    int k;
	tinit();cls();
    low=-2.0; high=2.0;
    for (k=1;k<=LIMIT;k++) {
        x=(low+high)/2;
        if (f(x)>0)
            high=x;
        else
            low=x;
        if (f(x)==0 || fabs(high-low)<fabs(low)*EPS){
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("�������Ȃ�\n");
	tfin();
}
