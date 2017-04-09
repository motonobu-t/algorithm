// Rei1View.cpp : CRei1View �N���X�̎���
//

#include "stdafx.h"
#include "Rei1.h"

#include "Rei1Doc.h"
#include "Rei1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei1View

IMPLEMENT_DYNCREATE(CRei1View, CFormView)

BEGIN_MESSAGE_MAP(CRei1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei1View �R���X�g���N�V����/�f�X�g���N�V����

CRei1View::CRei1View()
	: CFormView(CRei1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei1View::~CRei1View()
{
}

void CRei1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei1View �f�f

#ifdef _DEBUG
void CRei1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei1Doc* CRei1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei1Doc)));
	return (CRei1Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei1View ���b�Z�[�W �n���h��

/*
 * ------------------------------
 *      �Q�����in�br�̌v�Z�j    *
 * ------------------------------
 */

#include "mfcform.h"

long combi(int n,int r)
{
    int i;
    long p=1;

    for (i=1;i<=r;i++)
        p=p*(n-i+1)/i;
    return p;
}

void CRei1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int n,r;
	tinit();cls();
    for (n=0;n<=5;n++) {
        for (r=0;r<=n;r++)
            printf("%d�b%d=%ld  ",n,r,combi(n,r));
        printf("\n");
    }
	tfin();
}
