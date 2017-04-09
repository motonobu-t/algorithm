// Dr8_1View.cpp : CDr8_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr8_1.h"

#include "Dr8_1Doc.h"
#include "Dr8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr8_1View

IMPLEMENT_DYNCREATE(CDr8_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr8_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr8_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr8_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr8_1View::CDr8_1View()
	: CFormView(CDr8_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr8_1View::~CDr8_1View()
{
}

void CDr8_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr8_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr8_1View �f�f

#ifdef _DEBUG
void CDr8_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr8_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr8_1Doc* CDr8_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr8_1Doc)));
	return (CDr8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr8_1View ���b�Z�[�W �n���h��
/*
 * ----------------------
 *     ��l���̌���@   *
 * ----------------------
 */

#include "mfcform.h"

#define N 1000             /* �����̔����� */
#define M 10               /* ���������͈̔� */
#define F (N/M)            /* ���Ғl */
#define SCALE (40.0/F)     /* �q�X�g�O�����̍����i�����X�P�[���j */

unsigned rndnum=13;        /* �����̏����l */
unsigned irnd(void)        /* 0�`32767�̐������� */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0�`1�����̎������� */
{
    return irnd()/32767.1;
}

void CDr8_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,j,rank,hist[M+1];
    double e=0.0;

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1�`M�̗������P���� */
        hist[rank]++;
    }

	tinit();cls();
    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* �q�X�g�O�����̕\�� */
            printf("*");
        printf("\n");

        e=e+(double)(hist[i]-F)*(hist[i]-F)/F;        /* ��2�̌v�Z */
    }
    printf("��2=%f\n",e);
	tfin();
}
