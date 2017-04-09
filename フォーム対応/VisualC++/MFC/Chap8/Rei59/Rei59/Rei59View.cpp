// Rei59View.cpp : CRei59View �N���X�̎���
//

#include "stdafx.h"
#include "Rei59.h"

#include "Rei59Doc.h"
#include "Rei59View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei59View

IMPLEMENT_DYNCREATE(CRei59View, CFormView)

BEGIN_MESSAGE_MAP(CRei59View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei59View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei59View �R���X�g���N�V����/�f�X�g���N�V����

CRei59View::CRei59View()
	: CFormView(CRei59View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei59View::~CRei59View()
{
}

void CRei59View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei59View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei59View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei59View �f�f

#ifdef _DEBUG
void CRei59View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei59View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei59Doc* CRei59View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei59Doc)));
	return (CRei59Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei59View ���b�Z�[�W �n���h��
/*
 * ----------------------
 *       �������e       *
 * ----------------------
 */

#include "mfcform.h"
void rotate(double ax,double ay,double az,double x,double y,double z,
       double *px,double *py)      /* �R������]�ϊ� */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);        /* ������� */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                         /* ������� */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);     /* ������� */
    *py=x2*sin(az)+y2*cos(az);
}

void CRei59View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct {
        int f;
        double x,y,z;
    } a[]
    ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
      1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
      -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
      -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
      -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
      1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
      -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
      1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
      -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
      1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0  };

    int k;
    double ax=20*3.14159/180,
           ay=-45*3.14159/180,
           az=0*3.14159/180,
           px,py;

    ginit(); cls();
    window(-160,-100,160,100);

    for (k=0;a[k].f!=-999;k++){
        rotate(ax,ay,az,a[k].x,a[k].y,a[k].z,&px,&py);
        if (a[k].f==-1)          /* �n�_�Ȃ� */
            setpoint(px,py);
        else
            moveto(px,py);
    }
}
