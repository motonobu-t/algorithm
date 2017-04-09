// Dr63_2View.cpp : CDr63_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_2.h"

#include "Dr63_2Doc.h"
#include "Dr63_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_2View

IMPLEMENT_DYNCREATE(CDr63_2View, CView)

BEGIN_MESSAGE_MAP(CDr63_2View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_2View::CDr63_2View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_2View::~CDr63_2View()
{
}

BOOL CDr63_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr63_2View �`��
/*
 * -----------------
 *      �b�Ȑ�     *
 * -----------------
 */

#include "mfcglib.h"

void ccurve(int n)
{
    if (n==0){
        move(5);
    }
    else {
        ccurve(n-1);
        turn(90);
        ccurve(n-1);
        turn(-90);
    }
}

void CDr63_2View::OnDraw(CDC* pDC)
{
	CDr63_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int n=10;       /* ���� */

    ginit(); cls();

    setpoint(200,100);
    ccurve(n);
}


// CDr63_2View ���

BOOL CDr63_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr63_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr63_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr63_2View �f�f

#ifdef _DEBUG
void CDr63_2View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_2Doc* CDr63_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_2Doc)));
	return (CDr63_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_2View ���b�Z�[�W �n���h��
