// Rei2View.cpp : CRei2View �N���X�̎���
//

#include "stdafx.h"
#include "Rei2.h"

#include "Rei2Doc.h"
#include "Rei2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei2View

IMPLEMENT_DYNCREATE(CRei2View, CFormView)

BEGIN_MESSAGE_MAP(CRei2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei2View �R���X�g���N�V����/�f�X�g���N�V����

CRei2View::CRei2View()
	: CFormView(CRei2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei2View::~CRei2View()
{
}

void CRei2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei2View �f�f

#ifdef _DEBUG
void CRei2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei2Doc* CRei2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei2Doc)));
	return (CRei2Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei2View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *      �x�����z�i�q�X�g�O�����j     *
 * -----------------------------------
 */

#include "mfcform.h"

#define Num 20
void CRei2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={35,25,56,78,43,66,71,73,80,90,
              0,73,35,65,100,78,80,85,35,50};
    int i,rank,histo[11];

    for (i=0;i<=10;i++)
        histo[i]=0;

    for (i=0;i<Num;i++){
        rank=a[i]/10;        /* �ʑ� */
        if (0<=rank && rank<=10)
            histo[rank]++;
    }

	tinit();cls();
    for (i=0;i<=10;i++)
        printf("%3d -  :%3d\n",i*10,histo[i]);
	tfin();
}
