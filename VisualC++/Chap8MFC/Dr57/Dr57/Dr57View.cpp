// Dr57View.cpp : CDr57View �N���X�̎���
//

#include "stdafx.h"
#include "Dr57.h"

#include "Dr57Doc.h"
#include "Dr57View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr57View

IMPLEMENT_DYNCREATE(CDr57View, CView)

BEGIN_MESSAGE_MAP(CDr57View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr57View �R���X�g���N�V����/�f�X�g���N�V����

CDr57View::CDr57View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr57View::~CDr57View()
{
}

BOOL CDr57View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr57View �`��
/*
 * ------------------------
 *     �Q������]�ϊ�     *
 * ------------------------
 */

#include "mfcglib.h"

void multi(double factx,double facty,double *x,double *y)
{
    *x=factx*(*x);
    *y=facty*(*y);
}
void rotate(double deg,double *x,double *y)	/* ��]�ϊ� */
{
    double dx,dy,rd=3.14159/180;
    dx=(*x)*cos(deg*rd)-(*y)*sin(deg*rd);
    dy=(*x)*sin(deg*rd)+(*y)*cos(deg*rd);
    *x=dx; *y=dy;
}

void CDr57View::OnDraw(CDC* pDC)
{
	CDr57Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    double x[]={0,100,100,  0,0},
           y[]={0,  0,200,200,0};
    int j,k,n=5;

    ginit(); cls(); window(-320,-200,320,200);

    for (j=0;j<12;j++){
        for (k=0;k<n;k++){
            multi(.8,.8,&x[k],&y[k]);
            rotate(30,&x[k],&y[k]);
            if (k==0)
                setpoint(x[k],y[k]);
            else
                moveto(x[k],y[k]);
        }
    }
}


// CDr57View ���

BOOL CDr57View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr57View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr57View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr57View �f�f

#ifdef _DEBUG
void CDr57View::AssertValid() const
{
	CView::AssertValid();
}

void CDr57View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr57Doc* CDr57View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr57Doc)));
	return (CDr57Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr57View ���b�Z�[�W �n���h��
