// Dr20_1View.cpp : CDr20_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr20_1.h"

#include "Dr20_1Doc.h"
#include "Dr20_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_1View

IMPLEMENT_DYNCREATE(CDr20_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr20_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr20_1View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CDr20_1View::OnStnClickedPict)
END_MESSAGE_MAP()

// CDr20_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr20_1View::CDr20_1View()
	: CFormView(CDr20_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr20_1View::~CDr20_1View()
{
}

void CDr20_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr20_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr20_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr20_1View �f�f

#ifdef _DEBUG
void CDr20_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr20_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr20_1Doc* CDr20_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr20_1Doc)));
	return (CDr20_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr20_1View ���b�Z�[�W �n���h��
/*
 * -------------------------------------
 *      �����T���@�i�ԕ������Ă�j     *
 * -------------------------------------
 */

#include "mfcform.h"

#define N 10       /* �f�[�^���@*/

void CDr20_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct girl {
        char name[20];
        int age;
    } a[N+1]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
              "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i;

	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);

    strcpy(a[N].name,key);        /* �ԕ� */
    i=0;
    while (strcmp(key,a[i].name)!=0)
        i++;

	tinit();cls();
    if (i<N)
        printf("%s %d\n",a[i].name,a[i].age);
    else
        printf("������܂���ł���\n");
	tfin();
}

