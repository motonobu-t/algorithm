// Dr63_4View.cpp : CDr63_4View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_4.h"

#include "Dr63_4Doc.h"
#include "Dr63_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_4View

IMPLEMENT_DYNCREATE(CDr63_4View, CView)

BEGIN_MESSAGE_MAP(CDr63_4View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_4View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_4View::CDr63_4View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_4View::~CDr63_4View()
{
}

BOOL CDr63_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr63_4View �`��
/*
 * -------------------------
 *      �q���x���g�Ȑ�     *
 * -------------------------
 */

#include "mfcglib.h"

void hilbert(int n,double l,double angle)
{
    if (n==0)
        return;
    turn(angle);hilbert(n-1,l,-angle);move(l);
    turn(-angle);hilbert(n-1,l,angle);move(l);
    hilbert(n-1,l,angle);turn(-angle);move(l);
    hilbert(n-1,l,-angle);turn(angle);
}

void CDr63_4View::OnDraw(CDC* pDC)
{
	CDr63_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int n=4;         /* ���� */

    ginit(); cls();

    setpoint(200,100);
    hilbert(n,10,90);
}


// CDr63_4View ���

BOOL CDr63_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr63_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr63_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr63_4View �f�f

#ifdef _DEBUG
void CDr63_4View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_4Doc* CDr63_4View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_4Doc)));
	return (CDr63_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_4View ���b�Z�[�W �n���h��
