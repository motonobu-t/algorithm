// Rei60View.cpp : CRei60View �N���X�̎���
//

#include "stdafx.h"
#include "Rei60.h"

#include "Rei60Doc.h"
#include "Rei60View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei60View

IMPLEMENT_DYNCREATE(CRei60View, CView)

BEGIN_MESSAGE_MAP(CRei60View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei60View �R���X�g���N�V����/�f�X�g���N�V����

CRei60View::CRei60View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei60View::~CRei60View()
{
}

BOOL CRei60View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CRei60View �`��
/*
 * -------------------------------------
 *      ��]�̃��f���i���C���O���X�j   *
 * -------------------------------------
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

void CRei60View::OnDraw(CDC* pDC)
{
	CRei60Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int n,k;
    double x,z,px,py,ax,ay,az,rd=3.14159/180;
    double y[]={180,140,100,60,20,10,4,0,-999},   /* ���� */
           r[]={100,55,10,10,10,50,80,80,-999};   /* ���a */
    ax=35*rd;   /* �������̉�]�p */
    ay=0;       /* �������̉�]�p */
    az=20*rd;   /* �������̉�]�p */

    ginit(); cls();
    window(-320,-100,320,300);

    for (k=0;(int)y[k]!=-999;k++){    /* �������̉�]�O�� */
        for (n=0;n<=360;n=n+10){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (n==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
    for (n=0;n<=360;n=n+60){        /* �Ő� */
        for (k=0;(int)y[k]!=-999;k++){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (k==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }

}


// CRei60View ���

BOOL CRei60View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CRei60View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRei60View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CRei60View �f�f

#ifdef _DEBUG
void CRei60View::AssertValid() const
{
	CView::AssertValid();
}

void CRei60View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei60Doc* CRei60View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei60Doc)));
	return (CRei60Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei60View ���b�Z�[�W �n���h��
