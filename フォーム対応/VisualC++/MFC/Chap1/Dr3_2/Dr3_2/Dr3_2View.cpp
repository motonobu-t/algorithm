// Dr3_2View.cpp : CDr3_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr3_2.h"

#include "Dr3_2Doc.h"
#include "Dr3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr3_2View

IMPLEMENT_DYNCREATE(CDr3_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr3_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr3_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr3_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr3_2View::CDr3_2View()
	: CFormView(CDr3_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr3_2View::~CDr3_2View()
{
}

void CDr3_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr3_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr3_2View �f�f

#ifdef _DEBUG
void CDr3_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr3_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr3_2Doc* CDr3_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr3_2Doc)));
	return (CDr3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr3_2View ���b�Z�[�W �n���h��
/*
 * -----------------------------------
 *       ���ʕt���i���̃f�[�^�Łj    *
 * -----------------------------------
 */

#include "mfcform.h"

#define Num 10
#define Max 36
#define Min -20
#define Bias 1-(Min)    /* �ŏ��l��z��v�f�̂P�ɑΉ������� */

void CDr3_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={-3,2,3,-1,-2,-6,2,-1,1,5};
    int i,juni[Max+Bias+1];

	for (i=Min+Bias;i<=Max+Bias;i++)
        juni[i]=0;

    for (i=0;i<Num;i++)
        juni[a[i]+Bias]++;

    juni[0]=1;
    for (i=Min+Bias;i<=Max+Bias;i++)
        juni[i]=juni[i]+juni[i-1];

	tinit();cls();
    printf("�@���_�@����\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[a[i]+Bias-1]);
    }
	tfin();
}
