// Rei19View.cpp : CRei19View �N���X�̎���
//

#include "stdafx.h"
#include "Rei19.h"

#include "Rei19Doc.h"
#include "Rei19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei19View

IMPLEMENT_DYNCREATE(CRei19View, CFormView)

BEGIN_MESSAGE_MAP(CRei19View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei19View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei19View �R���X�g���N�V����/�f�X�g���N�V����

CRei19View::CRei19View()
	: CFormView(CRei19View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei19View::~CRei19View()
{
}

void CRei19View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei19View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei19View �f�f

#ifdef _DEBUG
void CRei19View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei19View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei19Doc* CRei19View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei19Doc)));
	return (CRei19Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei19View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      ��{�}���@     *
 * ---------------------
 */

#include "mfcform.h"

#define N 100     /* �f�[�^�� */

void CRei19View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[N],i,j,t;

    for(i=0;i<N;i++)       /* �m�̗��� */
        a[i]=rand();

    for (i=1;i<N;i++){
        for (j=i-1;j>=0;j--){
            if (a[j]>a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
            else
                break;
        }
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
