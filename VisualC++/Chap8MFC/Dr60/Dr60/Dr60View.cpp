// Dr60View.cpp : CDr60View �N���X�̎���
//

#include "stdafx.h"
#include "Dr60.h"

#include "Dr60Doc.h"
#include "Dr60View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr60View

IMPLEMENT_DYNCREATE(CDr60View, CView)

BEGIN_MESSAGE_MAP(CDr60View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr60View �R���X�g���N�V����/�f�X�g���N�V����

CDr60View::CDr60View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr60View::~CDr60View()
{
}

BOOL CDr60View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr60View �`��
/*
 * --------------------
 *      ���̃��f��    *
 * --------------------
 */

#include "mfcglib.h"
void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   /* �R������]�ϊ� */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          /* ������� */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           /* ������� */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       /* ������� */
    *py=x2*sin(az)+y2*cos(az);
}

void CDr60View::OnDraw(CDC* pDC)
{
	CDr60Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int k,n;
    double ax,ay,az,rd=3.14159/180;
    double x[]={ 0,20,  0, 60,100,60, 0,-999},   /* �����W */
           z[]={40,60,100,120, 60,20,40,-999},   /* �����W */
           h=100.0,                              /* ���� */
           btx[30],bty[30],                      /* ��� */
           tpx[30],tpy[30];                      /* ��� */
    ax=35*rd;                       /* �������̉�]�p */
    ay=-60*rd;                      /* �������̉�]�p */
    az=0;

    ginit(); cls();
    window(-320,-200,320,200);

    for (k=0;(int)x[k]!=-999;k++){      /* ��� */
        rotate(ax,ay,az,x[k],0.0,z[k],&btx[k],&bty[k]);
        if (k==0)
            setpoint(btx[k],bty[k]);
        else
            moveto(btx[k],bty[k]);
    }
    n=k;
    for (k=0;k<n;k++){                  /* ��� */
        rotate(ax,ay,az,x[k],h,z[k],&tpx[k],&tpy[k]);
        if (k==0)
            setpoint(tpx[k],tpy[k]);
        else
            moveto(tpx[k],tpy[k]);
    }
    for (k=0;k<n;k++)       /* ��ʂƏ�ʂ̊e�_������ */
        line(tpx[k],tpy[k],btx[k],bty[k]);
}


// CDr60View ���

BOOL CDr60View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr60View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr60View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr60View �f�f

#ifdef _DEBUG
void CDr60View::AssertValid() const
{
	CView::AssertValid();
}

void CDr60View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr60Doc* CDr60View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr60Doc)));
	return (CDr60Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr60View ���b�Z�[�W �n���h��
