// Dr17MFCView.cpp : CDr17MFCView �N���X�̎���
//

#include "stdafx.h"
#include "Dr17MFC.h"

#include "Dr17MFCDoc.h"
#include "Dr17MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr17MFCView

IMPLEMENT_DYNCREATE(CDr17MFCView, CView)

BEGIN_MESSAGE_MAP(CDr17MFCView, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr17MFCView �R���X�g���N�V����/�f�X�g���N�V����

CDr17MFCView::CDr17MFCView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr17MFCView::~CDr17MFCView()
{
}

BOOL CDr17MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr17MFCView �`��
/*
 * ---------------------
 *      �ŏ��Q��@     *
 * ---------------------
 */

#include "mfcglib.h"

#define N 7             /* �f�[�^�� */
#define M 5             /* ���Ă͂ߎ��� */

#define Max(a,b) (((a)>(b))?(a):(b))

double ipow(double p,int n)        /* ���O���@�����߂�֐� */
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}

void CDr17MFCView::OnDraw(CDC* pDC)
{
	CDr17MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    double x[]={-3,-2,-1, 0,1,2,3},
           y[]={ 5,-2,-3,-1,1,4,5},
           a[M+1][M+2],s[2*M+1],t[M+1];
    int i,j,k;
    double p,d;

    for (i=0;i<=2*M;i++)
        s[i]=0;
    for (i=0;i<=M;i++)
        t[i]=0;

    for (i=0;i<N;i++){
        for (j=0;j<=2*M;j++)               /* s0 ���� s2m �̌v�Z */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                 /* t0 ���� tm �̌v�Z */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] �� s[],t[] �̒l������ */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* �͂��o�� */
        p=a[k][k];
        for (j=k;j<=M+1;j++)
            a[k][j]=a[k][j]/p;
        for (i=0;i<=M;i++){
            if (i!=k){
                d=a[i][k];
                for (j=k;j<=M+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

	/* �W���̕\�� */
	CString buf;
	for (i=0;i<=M;i++){
		buf.Format(CString("a%d=%lf"),i,a[i][M+1]);
		pDC->TextOut(0,i*20,buf);
	}

    /* �O���t�̕\�� */
    double px,py,xmax,ymax,xmin,ymin,sx,sy,dx,dy,step;

    ginit();
    xmax=xmin=x[0];ymax=ymin=y[0];
    for (i=1;i<N;i++){
        if (x[i]<xmin) xmin=x[i];
        if (y[i]<ymin) ymin=y[i];
        if (x[i]>xmax) xmax=x[i];
        if (y[i]>ymax) ymax=y[i];
    }
    sx=1.2*Max(fabs(xmin),fabs(xmax)); /* �����̃T�C�Y */
    sy=1.2*Max(fabs(ymin),fabs(ymax)); /* �����̃T�C�Y */
    dx=sx/100;dy=sy/100;               /* �{��̃T�C�Y */
    step=(xmax-xmin)/100;              /* �v���b�g�Ԋu */

    window(-sx,-sy,sx,sy);

    line(-sx,0,sx,0);line(0,-sy,0,sy); /* ���� */

    for (i=0;i<N;i++){  /* �{��̃v���b�g */
        line(x[i]-dx,y[i],x[i]+dx,y[i]);
        line(x[i],y[i]-dy,x[i],y[i]+dy);
    }

    for (px=xmin;px<=xmax;px=px+step){ /* �O���t�̕`�� */
        py=0;
        for (i=0;i<=M;i++)
            py=py+a[i][M+1]*ipow(px,i);
        if (px==xmin)
            setpoint(px,py);
        else
            moveto(px,py);
    }
}


// CDr17MFCView ���

BOOL CDr17MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr17MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr17MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr17MFCView �f�f

#ifdef _DEBUG
void CDr17MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CDr17MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr17MFCDoc* CDr17MFCView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr17MFCDoc)));
	return (CDr17MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CDr17MFCView ���b�Z�[�W �n���h��
