// Dr59View.cpp : CDr59View �N���X�̎���
//

#include "stdafx.h"
#include "Dr59.h"

#include "Dr59Doc.h"
#include "Dr59View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr59View

IMPLEMENT_DYNCREATE(CDr59View, CView)

BEGIN_MESSAGE_MAP(CDr59View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr59View �R���X�g���N�V����/�f�X�g���N�V����

CDr59View::CDr59View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr59View::~CDr59View()
{
}

BOOL CDr59View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr59View �`��
/*
 * -------------------
 *      �����ϊ�     *
 * -------------------
 */

#include "mfcglib.h"

void CDr59View::OnDraw(CDC* pDC)
{
	CDr59Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    struct {
        int f;
        double x,y,z;
    }a[]
      ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
        1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
        -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
        -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
        -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
        1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
        -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
        1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
        -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
        1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0 };

    double ay=-35*3.14159/180,    /* �������̉�]�p */
           vp=-300.0,             /* ���e���S */
           l=-25.0,               /* �������̈ړ��� */
           m=-70.0,               /* �������̈ړ��� */
           n=0.0,                 /* �������̈ړ���*/
           h,px,py;
    int k;

    ginit(); cls();
    window(-320,-200,320,200);
    for (k=0;a[k].f!=-999;k++){
                                              /* �����ϊ� */
        h=-a[k].x*sin(ay)/vp+a[k].z*cos(ay)/vp+n/vp+1;
        px=(a[k].x*cos(ay)+a[k].z*sin(ay)+l)/h;
        py=(a[k].y+m)/h;

        if (a[k].f==-1)
            setpoint(px,py);
        else
            moveto(px,py);
    }
}


// CDr59View ���

BOOL CDr59View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr59View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr59View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr59View �f�f

#ifdef _DEBUG
void CDr59View::AssertValid() const
{
	CView::AssertValid();
}

void CDr59View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr59Doc* CDr59View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr59Doc)));
	return (CDr59Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr59View ���b�Z�[�W �n���h��
