// Dr58View.cpp : CDr58View �N���X�̎���
//

#include "stdafx.h"
#include "Dr58.h"

#include "Dr58Doc.h"
#include "Dr58View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr58View

IMPLEMENT_DYNCREATE(CDr58View, CView)

BEGIN_MESSAGE_MAP(CDr58View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr58View �R���X�g���N�V����/�f�X�g���N�V����

CDr58View::CDr58View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr58View::~CDr58View()
{
}

BOOL CDr58View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr58View �`��
/*
 * -------------------
 *      ��Q����     *
 * -------------------
 */

#include "mfcglib.h"

void CDr58View::OnDraw(CDC* pDC)
{
	CDr58Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int k;
    double leng=400.0,            /* �Ίp���̏����l */
           rd=3.14159/180,
           x,y;

    ginit(); cls();
    setpoint(0,380); setangle(-54.7);
    for (k=1;k<=10;k++){
        move(leng);                 /* �Ίp�������� */
        x=leng*cos(54.7*rd);        /* �������̒��� */
        y=leng*sin(54.7*rd);        /* �������̒��� */
        turn(180-35.3); move(y);    /* �����`��`�� */
        turn(90); move(x);
        turn(90); move(y);
        turn(90); move(x);
        turn(35.3);
        leng=leng/sqrt(2.0);
    }
}


// CDr58View ���

BOOL CDr58View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr58View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr58View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr58View �f�f

#ifdef _DEBUG
void CDr58View::AssertValid() const
{
	CView::AssertValid();
}

void CDr58View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr58Doc* CDr58View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr58Doc)));
	return (CDr58Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr58View ���b�Z�[�W �n���h��
