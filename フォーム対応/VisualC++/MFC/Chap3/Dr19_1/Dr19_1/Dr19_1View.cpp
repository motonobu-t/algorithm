// Dr19_1View.cpp : CDr19_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr19_1.h"

#include "Dr19_1Doc.h"
#include "Dr19_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr19_1View

IMPLEMENT_DYNCREATE(CDr19_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr19_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr19_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr19_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr19_1View::CDr19_1View()
	: CFormView(CDr19_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr19_1View::~CDr19_1View()
{
}

void CDr19_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr19_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr19_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr19_1View �f�f

#ifdef _DEBUG
void CDr19_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr19_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr19_1Doc* CDr19_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr19_1Doc)));
	return (CDr19_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr19_1View ���b�Z�[�W �n���h��
/*
 * ----------------------------------------
 *      �V�F���E�\�[�g�i���Ǒ}���@ �j     *
 * ----------------------------------------
 */

#include "mfcform.h"

#define N 100   /* �f�[�^�� */
void CDr19_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        /* �m�̗��� */
        a[i]=rand();

    gap=N/2;                /* �M���b�v�̏����l */
    while (gap>0){
        for (k=0;k<gap;k++){    /* �M���v�Ƃт̕�������̃\�[�g */
            for (i=k+gap;i<N;i=i+gap){
                for (j=i-gap;j>=k;j=j-gap){
                    if (a[j]>a[j+gap]){
                        t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                    }
                    else
                        break;
                }
            }
        }
        gap=gap/2;             /* �M���b�v�𔼕��ɂ��� */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
