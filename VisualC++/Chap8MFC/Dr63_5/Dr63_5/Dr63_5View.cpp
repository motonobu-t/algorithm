// Dr63_5View.cpp : CDr63_5View �N���X�̎���
//

#include "stdafx.h"
#include "Dr63_5.h"

#include "Dr63_5Doc.h"
#include "Dr63_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_5View

IMPLEMENT_DYNCREATE(CDr63_5View, CView)

BEGIN_MESSAGE_MAP(CDr63_5View, CView)
	// �W������R�}���h
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_5View �R���X�g���N�V����/�f�X�g���N�V����

CDr63_5View::CDr63_5View()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr63_5View::~CDr63_5View()
{
}

BOOL CDr63_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CDr63_5View �`��
/*
 * -------------------------------
 *      �V�F���s���X�L�[�Ȑ�     *
 * -------------------------------
 */

#include "mfcglib.h"

void sierpin(int n,double l)
{
    if (n==0){
        turn(-90);
        return;
    }
    sierpin(n-1,l);move(l);
    sierpin(n-1,l);turn(135);move(l);
    turn(135);sierpin(n-1,l);move(l);
    sierpin(n-1,l);
}

void CDr63_5View::OnDraw(CDC* pDC)
{
	CDr63_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
    int i,n =3,         /* ���� */
        leng=10;        /* ���� */

    ginit(); cls();

    setpoint(350,300);setangle(-45);
    for (i=0;i<4;i++){
        move(leng);
        sierpin(n,leng);
    }
}


// CDr63_5View ���

BOOL CDr63_5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// ����̈������
	return DoPreparePrinting(pInfo);
}

void CDr63_5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ����O�̓��ʂȏ�����������ǉ����Ă��������B
}

void CDr63_5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �����̌㏈����ǉ����Ă��������B
}


// CDr63_5View �f�f

#ifdef _DEBUG
void CDr63_5View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_5Doc* CDr63_5View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_5Doc)));
	return (CDr63_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_5View ���b�Z�[�W �n���h��
