// Dr7_3View.cpp : CDr7_3View �N���X�̎���
//

#include "stdafx.h"
#include "Dr7_3.h"

#include "Dr7_3Doc.h"
#include "Dr7_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr7_3View

IMPLEMENT_DYNCREATE(CDr7_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr7_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr7_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr7_3View �R���X�g���N�V����/�f�X�g���N�V����

CDr7_3View::CDr7_3View()
	: CFormView(CDr7_3View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr7_3View::~CDr7_3View()
{
}

void CDr7_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr7_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr7_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr7_3View �f�f

#ifdef _DEBUG
void CDr7_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr7_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr7_3Doc* CDr7_3View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr7_3Doc)));
	return (CDr7_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr7_3View ���b�Z�[�W �n���h��
/*
 * --------------------
 *     �f��������     *
 * --------------------
 */

#include "mfcform.h"

void CDr7_3View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int a,n;

	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
    a=2;

	tinit();cls();
    while (n>=a*a){
        if (n % a ==0){
            printf("%d*",a);n=n/a;
        }
        else
            a++;
    }
    printf("%d\n",n);
	tfin();
}
