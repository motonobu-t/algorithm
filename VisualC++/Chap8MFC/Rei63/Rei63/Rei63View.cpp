// Rei63View.cpp : CRei63View �N���X�̎���
//

#include "stdafx.h"
#include "Rei63.h"

#include "Rei63Doc.h"
#include "Rei63View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei63View

IMPLEMENT_DYNCREATE(CRei63View, CView)

BEGIN_MESSAGE_MAP(CRei63View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei63View �R���X�g���N�V����/�f�X�g���N�V����

CRei63View::CRei63View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei63View::~CRei63View()
{
}

BOOL CRei63View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CRei63View �`��
/*
 * -------------------------
 *      ���؋Ȑ����̂P     *
 * -------------------------
 */

#include "mfcglib.h"

double scale,branch;

void tree(int n,double x0,double y0,double leng,double angle)
                                        /* ���؋Ȑ��̍ċA�葱�� */
{
    if (n==0)
        return;

    setpoint(x0,y0); setangle(angle);
    move(leng);

    x0=LPX; y0=LPY;
    tree(n-1,x0,y0,leng/scale,angle-branch);
    tree(n-1,x0,y0,leng/scale,angle+branch);
}

void CRei63View::OnDraw(CDC* pDC)
{
	CRei63Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int n;
    double x0,y0,leng,angle;

    n=8;                /* �}�̎��� */
    x0=300.0;y0=50.0;   /* ���̈ʒu */
    leng=100.0;         /* �}�̒��� */
    angle=90.0;         /* �}�̌��� */
    scale=1.4;          /* �}�̐L�ї� */
    branch=20.0;        /* �}�̕���p */

    ginit(); cls();
    tree(n,x0,y0,leng,angle);
}


// CRei63View ���

BOOL CRei63View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CRei63View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRei63View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CRei63View �f�f

#ifdef _DEBUG
void CRei63View::AssertValid() const
{
	CView::AssertValid();
}

void CRei63View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei63Doc* CRei63View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei63Doc)));
	return (CRei63Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei63View ���b�Z�[�W �n���h��
