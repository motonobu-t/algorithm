// Dr18_1View.cpp : CDr18_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr18_1.h"

#include "Dr18_1Doc.h"
#include "Dr18_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr18_1View

IMPLEMENT_DYNCREATE(CDr18_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr18_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr18_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr18_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr18_1View::CDr18_1View()
	: CFormView(CDr18_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr18_1View::~CDr18_1View()
{
}

void CDr18_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr18_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr18_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr18_1View �f�f

#ifdef _DEBUG
void CDr18_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr18_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr18_1Doc* CDr18_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr18_1Doc)));
	return (CDr18_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr18_1View ���b�Z�[�W �n���h��
/*
 * -----------------------------
 *        �o�u���E�\�[�g       *
 * -----------------------------
 */

#include "mfcform.h"

#define N 6

void CDr18_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={80,41,35,90,40,20};
    int t,i,j;

    for (i=0;i<N-1;i++){
        for (j=N-1;j>i;j--){
            if (a[j]<a[j-1]){
                t=a[j];    a[j]=a[j-1]; a[j-1]=t;
            }
        }
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
