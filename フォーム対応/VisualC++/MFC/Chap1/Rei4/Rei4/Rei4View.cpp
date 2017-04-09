// Rei4View.cpp : CRei4View �N���X�̎���
//

#include "stdafx.h"
#include "Rei4.h"

#include "Rei4Doc.h"
#include "Rei4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei4View

IMPLEMENT_DYNCREATE(CRei4View, CFormView)

BEGIN_MESSAGE_MAP(CRei4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei4View �R���X�g���N�V����/�f�X�g���N�V����

CRei4View::CRei4View()
	: CFormView(CRei4View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei4View::~CRei4View()
{
}

void CRei4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei4View �f�f

#ifdef _DEBUG
void CRei4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei4Doc* CRei4View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei4Doc)));
	return (CRei4Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei4View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *    �����_���ȏ���i�����̈������@�j   *
 * ---------------------------------------
 */

#include "mfcform.h"

#define N 20

int irnd(int n)        /* �P�`���̗��� */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}

void CRei4View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i,j,flag,a[N+1];

    a[1]=irnd(N);
    for (i=2;i<=N;i++){
        do {
            a[i]=irnd(N);flag=0;
            for (j=1;j<i;j++)
                if (a[i]==a[j]){
                    flag=1;break;
                }
        } while (flag==1);
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
