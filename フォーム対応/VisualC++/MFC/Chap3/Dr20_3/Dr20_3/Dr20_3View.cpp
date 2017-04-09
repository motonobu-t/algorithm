// Dr20_3View.cpp : CDr20_3View �N���X�̎���
//

#include "stdafx.h"
#include "Dr20_3.h"

#include "Dr20_3Doc.h"
#include "Dr20_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_3View

IMPLEMENT_DYNCREATE(CDr20_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr20_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr20_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr20_3View �R���X�g���N�V����/�f�X�g���N�V����

CDr20_3View::CDr20_3View()
	: CFormView(CDr20_3View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr20_3View::~CDr20_3View()
{
}

void CDr20_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr20_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr20_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr20_3View �f�f

#ifdef _DEBUG
void CDr20_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr20_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr20_3Doc* CDr20_3View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr20_3Doc)));
	return (CDr20_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr20_3View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      ��{�}���@     *
 * ---------------------
 */

#include "mfcform.h"

#define N 100   /* �f�[�^�� */
void CDr20_3View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[N+1],i,j,t;

    for(i=1;i<=N;i++)        /* �m�̗��� */
        a[i]=rand();

    a[0]=-9999;              /* �ԕ� */
    for (i=2;i<=N;i++){
        t=a[i];
        for (j=i-1;a[j]>t;j--)
            a[j+1]=a[j];
        a[j+1]=t;
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
