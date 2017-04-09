// Dr56View.cpp : CDr56View �N���X�̎���
//

#include "stdafx.h"
#include "Dr56.h"

#include "Dr56Doc.h"
#include "Dr56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr56View

IMPLEMENT_DYNCREATE(CDr56View, CView)

BEGIN_MESSAGE_MAP(CDr56View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr56View �R���X�g���N�V����/�f�X�g���N�V����

CDr56View::CDr56View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr56View::~CDr56View()
{
}

BOOL CDr56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr56View �`��

/*
 * ----------------------
 *      �Q�����͗l      *
 * ----------------------
 */

#include "mfcglib.h"

void CDr56View::OnDraw(CDC* pDC)
{
	CDr56Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    double leng=200.0,    /* �ӂ̏����l */
           angle=89.0,    /* ��]�p */
           step=1.0;      /* �ӂ̌����l */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}


// CDr56View ���

BOOL CDr56View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr56View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr56View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr56View �f�f

#ifdef _DEBUG
void CDr56View::AssertValid() const
{
	CView::AssertValid();
}

void CDr56View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr56Doc* CDr56View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr56Doc)));
	return (CDr56Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr56View ���b�Z�[�W �n���h��
