// Rei58View.cpp : CRei58View �N���X�̎���
//

#include "stdafx.h"
#include "Rei58.h"

#include "Rei58Doc.h"
#include "Rei58View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei58View

IMPLEMENT_DYNCREATE(CRei58View, CView)

BEGIN_MESSAGE_MAP(CRei58View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei58View �R���X�g���N�V����/�f�X�g���N�V����

CRei58View::CRei58View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei58View::~CRei58View()
{
}

BOOL CRei58View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CRei58View �`��
/*
 * --------------------
 *       �Ώ̖͗l     *
 * --------------------
 */

#include "mfcglib.h"

#define N 9     /* �f�[�^�� */

void CRei58View::OnDraw(CDC* pDC)
{
	CRei58Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    double x[]={ 35, 19,10, 3,0,-3,-10,-19,-35},
           y[]={-20,-20,-5,-5,0,-5, -5,-20,-20};
    int a,b,j,k;
    double rd=3.14159/180,
           m,h,vy,vx,px,py;

    ginit(); cls();
    m=70.0; h=m*sqrt(3.0)/2;      /* ���R�p�`�̕ӂ̒����A���� */
    window(-m/2,-h/3,m/2,h*2/3);
    b=1;
    for (vy=0.0;vy<=310.0;vy=vy+h){
        a=1;
        for (vx=50.0;vx<=500.0;vx=vx+m/2){
            view(vx,vy,vx+m,vy+h);        /* �r���[�|�[�g�̐ݒ� */
            for (j=0;j<3;j++){
                for (k=0;k<N;k++){
                    px=x[k]*cos(120*j*rd)-y[k]*sin(120*j*rd);
                    py=x[k]*sin(120*j*rd)+y[k]*cos(120*j*rd);
                    if (a*b==-1)
                        py=-py+h/3;        /* �t���␳ */
                    if (k==0)
                        setpoint(px,py);
                    else
                        moveto(px,py);
                }
            }
            a=-a;
        }
        b=-b;
    }
}


// CRei58View ���

BOOL CRei58View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CRei58View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRei58View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CRei58View �f�f

#ifdef _DEBUG
void CRei58View::AssertValid() const
{
	CView::AssertValid();
}

void CRei58View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei58Doc* CRei58View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei58Doc)));
	return (CRei58Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei58View ���b�Z�[�W �n���h��
