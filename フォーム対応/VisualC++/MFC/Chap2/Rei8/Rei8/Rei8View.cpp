// Rei8View.cpp : CRei8View �N���X�̎���
//

#include "stdafx.h"
#include "Rei8.h"

#include "Rei8Doc.h"
#include "Rei8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei8View

IMPLEMENT_DYNCREATE(CRei8View, CFormView)

BEGIN_MESSAGE_MAP(CRei8View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei8View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei8View �R���X�g���N�V����/�f�X�g���N�V����

CRei8View::CRei8View()
	: CFormView(CRei8View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei8View::~CRei8View()
{
}

void CRei8View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei8View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei8View �f�f

#ifdef _DEBUG
void CRei8View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei8View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei8Doc* CRei8View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei8Doc)));
	return (CRei8Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei8View ���b�Z�[�W �n���h��
/*
 * --------------------------------
 *     ��l�����i���`�����@�j     *
 * --------------------------------
 */

#include "mfcform.h"

unsigned rndnum=13;        /* �����̏����l */
unsigned irnd(void)        /* 0�`32767�̐������� */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}

void CRei8View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int j;
	tinit();cls();
    for (j=0;j<100;j++){
        printf("%8d",irnd());
    }
	tfin();
}
