// Rei56View.cpp : CRei56View �N���X�̎���
//

#include "stdafx.h"
#include "Rei56.h"

#include "Rei56Doc.h"
#include "Rei56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei56View

IMPLEMENT_DYNCREATE(CRei56View, CView)

BEGIN_MESSAGE_MAP(CRei56View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei56View �R���X�g���N�V����/�f�X�g���N�V����

CRei56View::CRei56View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei56View::~CRei56View()
{
}

BOOL CRei56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CRei56View �`��

/*
 * -------------------------------
 *      ���m�p�`�i�|���S���j     *
 * -------------------------------
 */

#include "mfcglib.h"

void CRei56View::OnDraw(CDC* pDC)
{
	CRei56Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int j,n;

    ginit();cls();

    for (n=3;n<=9;n++){
        setpoint(200,50);
        setangle(0);
        for (j=0;j<n;j++){
            move(80);
            turn(360/n);
        }
    }
}


// CRei56View ���

BOOL CRei56View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CRei56View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CRei56View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CRei56View �f�f

#ifdef _DEBUG
void CRei56View::AssertValid() const
{
	CView::AssertValid();
}

void CRei56View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei56Doc* CRei56View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei56Doc)));
	return (CRei56Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei56View ���b�Z�[�W �n���h��
