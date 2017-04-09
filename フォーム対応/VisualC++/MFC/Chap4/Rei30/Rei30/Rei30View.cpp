// Rei30View.cpp : CRei30View �N���X�̎���
//

#include "stdafx.h"
#include "Rei30.h"

#include "Rei30Doc.h"
#include "Rei30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei30View

IMPLEMENT_DYNCREATE(CRei30View, CFormView)

BEGIN_MESSAGE_MAP(CRei30View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei30View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei30View �R���X�g���N�V����/�f�X�g���N�V����

CRei30View::CRei30View()
	: CFormView(CRei30View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei30View::~CRei30View()
{
}

void CRei30View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei30View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei30View �f�f

#ifdef _DEBUG
void CRei30View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei30View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei30Doc* CRei30View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei30Doc)));
	return (CRei30Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei30View ���b�Z�[�W �n���h��
/*
 * -------------------------------------------
 *      ���H�����ǂ�i�P����������j     *
 * -------------------------------------------
 */

#include "mfcform.h"

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success;
int visit(int i,int j)
{
    m[i][j]=1;                /* �K�ꂽ�ʒu�Ɉ������ */

    if (i==Ei && j==Ej)       /* �o���ɓ��B�����Ƃ� */
        success=1;
                               /* �o���ɓ��B���Ȃ��Ԗ��H�����܂悤 */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    if (success==1)          /* �ʉߓ_�̕\�� */
        printf("(%d,%d) ",i,j);
    return success;
}

void CRei30View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    success=0;                  /* �E�o�ɐ����������������t���O */
    Si=1; Sj=1; Ei=5; Ej=5;     /* �����Əo���̈ʒu */
	tinit();cls();
    printf("\n���H�̒T��\n");
    if (visit(Si,Sj)==0)
        printf("�o���͌�����܂���ł���\n");
    printf("\n");
	tfin();
}
