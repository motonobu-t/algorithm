// Dr65View.cpp : CDr65View �N���X�̎���
//

#include "stdafx.h"
#include "Dr65.h"

#include "Dr65Doc.h"
#include "Dr65View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr65View

IMPLEMENT_DYNCREATE(CDr65View, CFormView)

BEGIN_MESSAGE_MAP(CDr65View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr65View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr65View �R���X�g���N�V����/�f�X�g���N�V����

CDr65View::CDr65View()
	: CFormView(CDr65View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr65View::~CDr65View()
{
}

void CDr65View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr65View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr65View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr65View �f�f

#ifdef _DEBUG
void CDr65View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr65View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr65Doc* CDr65View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr65Doc)));
	return (CDr65Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr65View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      �헪��������񂯂�     *
 * -------------------------------
 */

#include "mfcform.h"

int man,computer,C=0,M=0,judge;
int table[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},    /* �헪�e�[�u�� */
                    {{0,0,0},{0,0,0},{0,0,0}},
                    {{0,0,0},{0,0,0},{0,0,0}}},
    hist[3]={0,0,0};                       /* ���s�̓x�� */
char *hand[3]={"�O�[","�`���L","�p�["};

void CDr65View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	if (table[C][M][0]>table[C][M][1] && table[C][M][0]>table[C][M][2])
        computer=0;
    else if (table[C][M][1]>table[C][M][2])
        computer=1;
    else
        computer=2;
	CString buf;
	text1.GetWindowText(buf);
	man=stoi(buf);

    printf("�R���s���[�^�̎� %s\n",hand[computer]);
    judge=(computer-man+3)%3;         /* ���� */
    switch (judge){
        case 0: printf("�Ђ��킯\n");
                table[C][M][(computer+2)%3]++;break;
        case 1: printf("���Ȃ��̏���\n");
                table[C][M][computer]--;break;
        case 2: printf("�R���s���[�^�̏���\n");
                table[C][M][computer]++;break;
    }
    M=man;               /* �P�O�̏�Ԃ�ۑ� */
    C=computer;

    hist[judge]++;
    printf("--- %d��%d�s%d�� ---\n\n",hist[1],hist[2],hist[0]);
	tfin();
}
