// Rei3View.cpp : CRei3View �N���X�̎���
//

#include "stdafx.h"
#include "Rei3.h"

#include "Rei3Doc.h"
#include "Rei3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei3View

IMPLEMENT_DYNCREATE(CRei3View, CFormView)

BEGIN_MESSAGE_MAP(CRei3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei3View �R���X�g���N�V����/�f�X�g���N�V����

CRei3View::CRei3View()
	: CFormView(CRei3View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei3View::~CRei3View()
{
}

void CRei3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei3View �f�f

#ifdef _DEBUG
void CRei3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei3Doc* CRei3View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei3Doc)));
	return (CRei3Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei3View ���b�Z�[�W �n���h��
/*
 * -------------------
 *      ���ʕt��     *
 * -------------------
 */

#include "mfcform.h"

#define Num 10
void CRei3View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={56,25,67,88,100,61,55,67,76,56};
    int juni[Num];
    int i,j;

    for (i=0;i<Num;i++){
        juni[i]=1;
        for (j=0;j<Num;j++){
            if (a[j]>a[i])
                juni[i]++;
        }
    }

	tinit();cls();
    printf("�@���_�@����\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[i]);
    }
	tfin();
}
