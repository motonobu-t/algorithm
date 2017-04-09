// Rei15View.cpp : CRei15View �N���X�̎���
//

#include "stdafx.h"
#include "Rei15.h"

#include "Rei15Doc.h"
#include "Rei15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei15View

IMPLEMENT_DYNCREATE(CRei15View, CFormView)

BEGIN_MESSAGE_MAP(CRei15View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei15View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei15View �R���X�g���N�V����/�f�X�g���N�V����

CRei15View::CRei15View()
	: CFormView(CRei15View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei15View::~CRei15View()
{
}

void CRei15View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei15View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei15View �f�f

#ifdef _DEBUG
void CRei15View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei15View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei15Doc* CRei15View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei15Doc)));
	return (CRei15Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei15View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------------
 *      �A���������̉�@�i�K�E�X�E�W�����_���@�j     *
 * ---------------------------------------------------
 */

#include "mfcform.h"

#define N 3     /* ���̐� */
void CRei15View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                      {4.0  ,1.0  ,-3.0 ,-2.0 },
                      {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d;
    int i,j,k;

    for (k=0;k<N;k++){
        p=a[k][k];                /* �s�{�b�g�W�� */
        for (j=k;j<N+1;j++)       /* �s�{�b�g�s�����Ŋ��� */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){        /* �s�{�b�g��̑|���o�� */
            if (i!=k){
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

	tinit();cls();
    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);
	tfin();

}
