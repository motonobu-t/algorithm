// Dr6View.cpp : CDr6View �N���X�̎���
//

#include "stdafx.h"
#include "Dr6.h"

#include "Dr6Doc.h"
#include "Dr6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr6View

IMPLEMENT_DYNCREATE(CDr6View, CFormView)

BEGIN_MESSAGE_MAP(CDr6View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr6View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CDr6View::OnStnClickedPict)
END_MESSAGE_MAP()

// CDr6View �R���X�g���N�V����/�f�X�g���N�V����

CDr6View::CDr6View()
	: CFormView(CDr6View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr6View::~CDr6View()
{
}

void CDr6View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr6View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr6View �f�f

#ifdef _DEBUG
void CDr6View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr6View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr6Doc* CDr6View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr6Doc)));
	return (CDr6Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr6View ���b�Z�[�W �n���h��
/*
 * ---------------------------------
 *      ���[�N���b�h�̌ݏ��@       *
 * ---------------------------------
 */

#include "mfcform.h"

void CDr6View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a,b,m,n,k;

	CString buf;
	text1.GetWindowText(buf);
	a=stoi(buf);
	text2.GetWindowText(buf);
	b=stoi(buf);
    m=a; n=b;
    do{
        k=m % n;
        m=n; n=k;
    } while(k!=0);

	tinit();cls();
    printf("�ő����=%d\n",m);
	tfin();
}

//void CDr6View::OnStnClickedPict()
//{
//	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
//}
