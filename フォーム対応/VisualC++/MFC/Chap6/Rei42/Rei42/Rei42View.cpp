// Rei42View.cpp : CRei42View �N���X�̎���
//

#include "stdafx.h"
#include "Rei42.h"

#include "Rei42Doc.h"
#include "Rei42View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei42View

IMPLEMENT_DYNCREATE(CRei42View, CFormView)

BEGIN_MESSAGE_MAP(CRei42View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei42View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei42View �R���X�g���N�V����/�f�X�g���N�V����

CRei42View::CRei42View()
	: CFormView(CRei42View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei42View::~CRei42View()
{
}

void CRei42View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei42View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei42View �f�f

#ifdef _DEBUG
void CRei42View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei42View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei42Doc* CRei42View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei42Doc)));
	return (CRei42Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei42View ���b�Z�[�W �n���h��
/*
 * -------------------------------
 *      �Q���T���؂̔z��\��     *
 * -------------------------------
 */

#include "mfcform.h"

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* �������؂ւ̃|�C���^ */
    char name[12];
    int right;          /* �E�����؂ւ̃|�C���^ */
};

void CRei42View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct tnode a[MaxSize]={{  1,"Machilda",  2},{  3,"Candy",  4},
                             {  5,"Rolla"   ,nil},{nil,"Ann"  ,nil},
                             {  6,"Emy"     ,  7},{nil,"Nancy",nil},
                             {nil,"Eluza"   ,nil},{nil,"Lisa" ,nil}};
    char key[12];
    int p;

	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
	tinit();cls();
    p=0;
    while (p!=nil){
        if (strcmp(key,a[p].name)==0){
            printf("������܂���\n");
            break;
        }
        else if (strcmp(key,a[p].name)<0)
            p=a[p].left;                    /* �������؂ֈړ� */
        else
            p=a[p].right;                   /* �E�����؂ֈړ� */
    }
	tfin();
}
