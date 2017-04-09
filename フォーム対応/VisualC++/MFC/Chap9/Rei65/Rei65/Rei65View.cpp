// Rei65View.cpp : CRei65View �N���X�̎���
//

#include "stdafx.h"
#include "Rei65.h"

#include "Rei65Doc.h"
#include "Rei65View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei65View

IMPLEMENT_DYNCREATE(CRei65View, CFormView)

BEGIN_MESSAGE_MAP(CRei65View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei65View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei65View �R���X�g���N�V����/�f�X�g���N�V����

CRei65View::CRei65View()
	: CFormView(CRei65View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei65View::~CRei65View()
{
}

void CRei65View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei65View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei65View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei65View �f�f

#ifdef _DEBUG
void CRei65View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei65View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei65Doc* CRei65View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei65Doc)));
	return (CRei65Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei65View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      �헪��������񂯂�     *
 * -------------------------------
 */

#include "mfcform.h"

int man,computer,M=0,judge;
int table[3][3]={{0,0,0},    /* �헪�e�[�u�� */
                 {0,0,0},
                 {0,0,0}},
    hist[3]={0,0,0};    /* ���s�̓x�� */
char *hand[3]={"�O�[","�`���L","�p�["};

void CRei65View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	if (table[M][0]>table[M][1] && table[M][0]>table[M][2])
        computer=2;
    else if (table[M][1]>table[M][2])
        computer=0;
    else
        computer=1;

	CString buf;
	text1.GetWindowText(buf);
	man=stoi(buf);
    printf("�R���s���[�^�̎� %s\n",hand[computer]);

    judge=(computer-man+3)%3;
    switch (judge){
        case 0: printf("�Ђ��킯\n");break;
        case 1: printf("���Ȃ��̏���\n");break;
        case 2: printf("�R���s���[�^�̏���\n");break;
    }
    hist[judge]++;
    table[M][man]++;        /* �w�K */
    M=man;
    printf("--- %d��%d�s%d�� ---\n\n",hist[1],hist[2],hist[0]);
	tfin();
}
