// Rei21View.cpp : CRei21View �N���X�̎���
//

#include "stdafx.h"
#include "Rei21.h"

#include "Rei21Doc.h"
#include "Rei21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei21View

IMPLEMENT_DYNCREATE(CRei21View, CFormView)

BEGIN_MESSAGE_MAP(CRei21View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei21View::OnBnClickedButton1)
//	ON_EN_CHANGE(IDC_EDIT1, &CRei21View::OnEnChangeEdit1)
END_MESSAGE_MAP()

// CRei21View �R���X�g���N�V����/�f�X�g���N�V����

CRei21View::CRei21View()
	: CFormView(CRei21View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei21View::~CRei21View()
{
}

void CRei21View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei21View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei21View �f�f

#ifdef _DEBUG
void CRei21View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei21View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei21Doc* CRei21View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei21Doc)));
	return (CRei21Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei21View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      �Q���T���@     *
 * ---------------------
 */

#include "mfcform.h"

#define N 10       /* �f�[�^���@*/

void CRei21View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid,flag=0;

	tinit();cls();
	CString buf;
	text1.GetWindowText(buf);
	key=stoi(buf);

	low=0;high=N-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid]==key){
            printf("%d �� %d �Ԗڂɂ���܂���\n",a[mid],mid);
            flag=1;
            break;
        }
        if (a[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }
    if (flag!=1)
        printf("������܂���ł���\n");
	tfin();
}

