// Rei6View.cpp : CRei6View �N���X�̎���
//

#include "stdafx.h"
#include "Rei6.h"

#include "Rei6Doc.h"
#include "Rei6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei6View

IMPLEMENT_DYNCREATE(CRei6View, CFormView)

BEGIN_MESSAGE_MAP(CRei6View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei6View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei6View �R���X�g���N�V����/�f�X�g���N�V����

CRei6View::CRei6View()
	: CFormView(CRei6View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei6View::~CRei6View()
{
}

void CRei6View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei6View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei6View �f�f

#ifdef _DEBUG
void CRei6View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei6View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei6Doc* CRei6View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei6Doc)));
	return (CRei6Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei6View ���b�Z�[�W �n���h��
/*
 * ---------------------------------
 *      ���[�N���b�h�̌ݏ��@       *
 * ---------------------------------
 */

#include "mfcform.h"

void CRei6View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a,b,m,n;

	CString buf;
	text1.GetWindowText(buf);
	a=stoi(buf);
	text2.GetWindowText(buf);
	b=stoi(buf);

    m=a; n=b;
    while (m!=n){
        if (m>n)
            m=m-n;
        else
            n=n-m;
    }

	tinit();cls();
    printf("�ő����=%d\n",m);
	tfin();
}
