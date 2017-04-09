// Rei57View.cpp : CRei57View �N���X�̎���
//

#include "stdafx.h"
#include "Rei57.h"

#include "Rei57Doc.h"
#include "Rei57View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei57View

IMPLEMENT_DYNCREATE(CRei57View, CView)

BEGIN_MESSAGE_MAP(CRei57View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei57View �R���X�g���N�V����/�f�X�g���N�V����

CRei57View::CRei57View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei57View::~CRei57View()
{
}

BOOL CRei57View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CRei57View �`��
/*
 * -------------------
 *      �Ώ̈ړ�     *
 * -------------------
 */

#include "mfcglib.h"

void mirror(int flag,double m,double *dat)    /* �Ώ̈ړ� */
{
    int i;
    for (i=1;i<=2*dat[0];i=i+2){    /* dat[0]�̓f�[�^�� */
        if (flag==1)                /* �������S */
            dat[i]=2*m-dat[i];
        if (flag==0)                /* �������S */
            dat[i+1]=2*m-dat[i+1];
    }
}
void draw(double *dat)              /* �}�`�̕`�� */
{
    int i;
    setpoint(dat[1],dat[2]);        /* �n�_ */
    for (i=3;i<=2*dat[0];i=i+2)     /* dat[0]�̓f�[�^�� */
        moveto(dat[i],dat[i+1]);
}

void CRei57View::OnDraw(CDC* pDC)
{
	CRei57Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    double a[]={11,0,80,5,75,17,80,20,60,15,55,0,55,
                 0,20,10,40,20,40,10,20,0,20};
    ginit(); cls(); window(-160,-100,160,100);

    draw(a);
    mirror(1,0.0,a);draw(a);
    mirror(0,0.0,a);draw(a);
    mirror(1,0.0,a);draw(a);
}


// CRei57View ���

BOOL CRei57View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CRei57View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRei57View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CRei57View �f�f

#ifdef _DEBUG
void CRei57View::AssertValid() const
{
	CView::AssertValid();
}

void CRei57View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei57Doc* CRei57View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei57Doc)));
	return (CRei57Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei57View ���b�Z�[�W �n���h��
