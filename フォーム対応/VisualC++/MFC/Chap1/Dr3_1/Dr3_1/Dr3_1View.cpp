// Dr3_1View.cpp : CDr3_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr3_1.h"

#include "Dr3_1Doc.h"
#include "Dr3_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr3_1View

IMPLEMENT_DYNCREATE(CDr3_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr3_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr3_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr3_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr3_1View::CDr3_1View()
	: CFormView(CDr3_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr3_1View::~CDr3_1View()
{
}

void CDr3_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr3_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr3_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr3_1View �f�f

#ifdef _DEBUG
void CDr3_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr3_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr3_1Doc* CDr3_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr3_1Doc)));
	return (CDr3_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr3_1View ���b�Z�[�W �n���h��
/*
 * ----------------------------
 *      ���ʕt���i���ǔŁj    *
 * ----------------------------
 */

#include "mfcform.h"

#define Num 10
#define Max 100
#define Min 0
void CDr3_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={56,25,67,88,100,61,55,67,76,56};
    int i,juni[Max+2];
    for (i=Min;i<=Max;i++)
        juni[i]=0;

    for (i=0;i<Num;i++)
        juni[a[i]]++;

    juni[Max+1]=1;
    for (i=Max;i>=Min;i--)
        juni[i]=juni[i]+juni[i+1];

	tinit();cls();
    printf("�@���_�@����\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[a[i]+1]);
    }
	tfin();
}
