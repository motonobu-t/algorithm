// Dr63_3View.cpp : CDr63_3View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_3.h"

#include "Dr63_3Doc.h"
#include "Dr63_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_3View

IMPLEMENT_DYNCREATE(CDr63_3View, CView)

BEGIN_MESSAGE_MAP(CDr63_3View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_3View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_3View::CDr63_3View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_3View::~CDr63_3View()
{
}

BOOL CDr63_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr63_3View �`��
/*
 * ---------------------------
 *      �h���S���E�J�[�u     *
 * ---------------------------
 */

#include "mfcglib.h"

void dragon(int n,double a)
{
    if (n==0){
        move(5);
    }
    else {
        dragon(n-1,90);
        turn(a);
        dragon(n-1,-90);
    }
}

void CDr63_3View::OnDraw(CDC* pDC)
{
	CDr63_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int n=10;       /* ���� */

    ginit(); cls();

    setpoint(200,100);
    dragon(n,90);
}


// CDr63_3View ���

BOOL CDr63_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr63_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr63_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr63_3View �f�f

#ifdef _DEBUG
void CDr63_3View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_3Doc* CDr63_3View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_3Doc)));
	return (CDr63_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_3View ���b�Z�[�W �n���h��
