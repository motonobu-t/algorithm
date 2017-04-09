// Rei7View.cpp : CRei7View �N���X�̎���
//

#include "stdafx.h"
#include "Rei7.h"

#include "Rei7Doc.h"
#include "Rei7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei7View

IMPLEMENT_DYNCREATE(CRei7View, CFormView)

BEGIN_MESSAGE_MAP(CRei7View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei7View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei7View �R���X�g���N�V����/�f�X�g���N�V����

CRei7View::CRei7View()
	: CFormView(CRei7View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei7View::~CRei7View()
{
}

void CRei7View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei7View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei7View �f�f

#ifdef _DEBUG
void CRei7View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei7View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei7Doc* CRei7View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei7Doc)));
	return (CRei7Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei7View ���b�Z�[�W �n���h��
/*
 * -----------------------
 *       �f���̔���      *
 * -----------------------
 */

#include "mfcform.h"

void CRei7View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,n,Limit;

	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);

	tinit();cls();
    if (n>=2){
        Limit=(int)sqrt((double)n);
        for (i=Limit;i>1;i--){
            if (n%i == 0)
                break;
        }
        if (i==1)
            printf("�f��\n");
        else
            printf("�f���łȂ�\n");
    }
	tfin();
}
