// Rei20View.cpp : CRei20View �N���X�̎���
//

#include "stdafx.h"
#include "Rei20.h"

#include "Rei20Doc.h"
#include "Rei20View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei20View

IMPLEMENT_DYNCREATE(CRei20View, CFormView)

BEGIN_MESSAGE_MAP(CRei20View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei20View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei20View �R���X�g���N�V����/�f�X�g���N�V����

CRei20View::CRei20View()
	: CFormView(CRei20View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei20View::~CRei20View()
{
}

void CRei20View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei20View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei20View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei20View �f�f

#ifdef _DEBUG
void CRei20View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei20View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei20Doc* CRei20View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei20Doc)));
	return (CRei20Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei20View ���b�Z�[�W �n���h��
/*
 * ---------------------
 *      �����T���@     *
 * ---------------------
 */

#include "mfcform.h"

#define N 10       /* �f�[�^���@*/

void CRei20View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct girl {
        char name[20];
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i;

	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);

    i=0;
    while (i<N && strcmp(key,a[i].name)!=0)
        i++;

	tinit();cls();
    if (i<N)
        printf("%s %d\n",a[i].name,a[i].age);
    else
        printf("������܂���ł���\n");
	tfin();
}
