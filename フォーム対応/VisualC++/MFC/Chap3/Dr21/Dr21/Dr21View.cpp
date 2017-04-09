// Dr21View.cpp : CDr21View �N���X�̎���
//

#include "stdafx.h"
#include "Dr21.h"

#include "Dr21Doc.h"
#include "Dr21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr21View

IMPLEMENT_DYNCREATE(CDr21View, CFormView)

BEGIN_MESSAGE_MAP(CDr21View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr21View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr21View �R���X�g���N�V����/�f�X�g���N�V����

CDr21View::CDr21View()
	: CFormView(CDr21View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr21View::~CDr21View()
{
}

void CDr21View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr21View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr21View �f�f

#ifdef _DEBUG
void CDr21View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr21View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr21Doc* CDr21View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr21Doc)));
	return (CDr21Doc*)m_pDocument;
}
#endif //_DEBUG

/*
 * --------------------
 *     �Q���T���@     *
 * --------------------
 */

#include "mfcform.h"

#define N 10       /* �f�[�^���@*/
// CDr21View ���b�Z�[�W �n���h��

void CDr21View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid;


	CString buf;
	text1.GetWindowText(buf);
	key=stoi(buf);

    low=0;high=N-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid]<=key)
            low=mid+1;
        if (a[mid]>=key)
            high=mid-1;
    }

	tinit();cls();
    if (low==high+2)
        printf("%d �� %d �Ԗڂɂ���܂���\n",a[mid],mid);
    else
        printf("������܂���ł���\n");
	tfin();
}
