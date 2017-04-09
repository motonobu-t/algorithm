// Dr26_2View.cpp : CDr26_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr26_2.h"

#include "Dr26_2Doc.h"
#include "Dr26_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_2View

IMPLEMENT_DYNCREATE(CDr26_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr26_2View::CDr26_2View()
	: CFormView(CDr26_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr26_2View::~CDr26_2View()
{
}

void CDr26_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr26_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr26_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_2View �f�f

#ifdef _DEBUG
void CDr26_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_2Doc* CDr26_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_2Doc)));
	return (CDr26_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_2View ���b�Z�[�W �n���h��
/*
 * ------------------------------
 *      n�br�̌v�Z�i�ċA�Łj    *
 * ------------------------------
 */

#include "mfcform.h"
long combi(int n,int r)
{
    if (r==0 || r==n)
        return 1L;
    else
        return combi(n-1,r)+combi(n-1,r-1);
}

void CDr26_2View::OnBnClickedButton1()
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
