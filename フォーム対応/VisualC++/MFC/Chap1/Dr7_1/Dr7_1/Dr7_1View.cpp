// Dr7_1View.cpp : CDr7_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr7_1.h"

#include "Dr7_1Doc.h"
#include "Dr7_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr7_1View

IMPLEMENT_DYNCREATE(CDr7_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr7_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr7_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr7_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr7_1View::CDr7_1View()
	: CFormView(CDr7_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr7_1View::~CDr7_1View()
{
}

void CDr7_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr7_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr7_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr7_1View �f�f

#ifdef _DEBUG
void CDr7_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr7_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr7_1Doc* CDr7_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr7_1Doc)));
	return (CDr7_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr7_1View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------
 *       �Q�`�m�̒�����f�����E���o��      *
 * -----------------------------------------
 */

#include "mfcform.h"

#define NUM 1000

void CDr7_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int prime[NUM/2+1];
    int i,n,m=0,Limit;

    for (n=2;n<=NUM;n++){
        Limit=(int)sqrt((double)n);
        for (i=Limit;i>1;i--){
            if (n%i == 0)
                break;
        }
        if (i==1)
            prime[m++]=n;
    }

	tinit();cls();
    printf("\n���߂�ꂽ�f��\n");
	for (i=0;i<m;i++)
        printf("%5d",prime[i]);
	tfin();
}
