// Dr2View.cpp : CDr2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr2.h"

#include "Dr2Doc.h"
#include "Dr2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr2View

IMPLEMENT_DYNCREATE(CDr2View, CFormView)

BEGIN_MESSAGE_MAP(CDr2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr2View �R���X�g���N�V����/�f�X�g���N�V����

CDr2View::CDr2View()
	: CFormView(CDr2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr2View::~CDr2View()
{
}

void CDr2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr2View �f�f

#ifdef _DEBUG
void CDr2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr2Doc* CDr2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr2Doc)));
	return (CDr2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr2View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      �Í��̉��     *
 * ---------------------
 */

#include "mfcform.h"

void CDr2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    char table[]={'Q','W','E','R','T','Y','U','I','O','P',
                  'A','S','D','F','G','H','J','K','L','Z',
                  'X','C','V','B','N','M','?'};
    char *p,*ango="KSOIDHEPZ";
    int index;
	tinit();cls();
    p=ango;
    while (*p!='\0'){
        if ('A'<=*p && *p<='Z')
            index=*p-'A';
        else
            index=26;
        putchar(table[index]);
        p++;
    }
    printf("\n");
	tfin();
}
