// Dr13View.cpp : CDr13View �N���X�̎���
//

#include "stdafx.h"
#include "Dr13.h"

#include "Dr13Doc.h"
#include "Dr13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr13View

IMPLEMENT_DYNCREATE(CDr13View, CFormView)

BEGIN_MESSAGE_MAP(CDr13View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr13View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr13View �R���X�g���N�V����/�f�X�g���N�V����

CDr13View::CDr13View()
	: CFormView(CDr13View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr13View::~CDr13View()
{
}

void CDr13View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr13View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr13View �f�f

#ifdef _DEBUG
void CDr13View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr13View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr13Doc* CDr13View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr13Doc)));
	return (CDr13Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr13View ���b�Z�[�W �n���h��
/*
 * -------------------
 *      �����v�Z     *
 * -------------------
 */

#include "mfcform.h"

#define KETA 20             /* ���� */
#define N ((KETA-1)/4+1)    /* �z��T�C�Y */

void lmul(short a[],short b,short c[])    /* �����O���~�V���[�g�� */
{
    short i;long d,cy=0;
    for (i=N-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}
void ldiv(short a[],short b,short c[])    /* �����O�����V���[�g�� */
{
    short i;long d,rem=0;
    for (i=0;i<N;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}
void print(short c[])            /* �����O���̕\�� */
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}

void CDr13View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    short a[N+2]={   0,3050,2508,8080,1233},
          c[N+2];
	tinit();cls();
    lmul(a,101,c); print(c);
    ldiv(a,200,c); print(c);
	tfin();
}
