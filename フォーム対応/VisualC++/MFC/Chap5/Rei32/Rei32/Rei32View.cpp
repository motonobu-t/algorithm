// Rei32View.cpp : CRei32View �N���X�̎���
//

#include "stdafx.h"
#include "Rei32.h"

#include "Rei32Doc.h"
#include "Rei32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei32View

IMPLEMENT_DYNCREATE(CRei32View, CFormView)

BEGIN_MESSAGE_MAP(CRei32View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei32View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei32View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei32View �R���X�g���N�V����/�f�X�g���N�V����

CRei32View::CRei32View()
	: CFormView(CRei32View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei32View::~CRei32View()
{
}

void CRei32View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei32View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei32View �f�f

#ifdef _DEBUG
void CRei32View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei32View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei32Doc* CRei32View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei32Doc)));
	return (CRei32Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei32View ���b�Z�[�W �n���h��
/*
 * -------------------
 *      �X�^�b�N     *
 * -------------------
 */

#include "mfcform.h"

#define MaxSize 100     /* �X�^�b�N�E�T�C�Y */
int stack[MaxSize];     /* �X�^�b�N */
int sp=0;               /* �X�^�b�N�E�|�C���^ */
int push(int n)        /* �X�^�b�N�Ƀf�[�^��ςގ葱�� */
{
    if (sp<MaxSize){
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* �X�^�b�N����t�̂Ƃ� */
}
int pop(int *n)        /* �X�^�b�N����f�[�^�����o���葱�� */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* �X�^�b�N����̂Ƃ� */
}

void CRei32View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
	if (push(n)==-1){
       printf("�X�^�b�N����t�ł�\n");
    }
	tfin();
}

void CRei32View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	tinit();cls();
	if (pop(&n)==-1)
        printf("�X�^�b�N�͋�ł�\n");
    else
        printf("stack data --> %d\n",n);
	tfin();
}
