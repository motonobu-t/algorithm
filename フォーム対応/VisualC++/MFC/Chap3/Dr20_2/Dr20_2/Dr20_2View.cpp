// Dr20_2View.cpp : CDr20_2View �N���X�̎���
//

#include "stdafx.h"
#include "Dr20_2.h"

#include "Dr20_2Doc.h"
#include "Dr20_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_2View

IMPLEMENT_DYNCREATE(CDr20_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr20_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr20_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr20_2View �R���X�g���N�V����/�f�X�g���N�V����

CDr20_2View::CDr20_2View()
	: CFormView(CDr20_2View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr20_2View::~CDr20_2View()
{
}

void CDr20_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr20_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr20_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr20_2View �f�f

#ifdef _DEBUG
void CDr20_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr20_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr20_2Doc* CDr20_2View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr20_2Doc)));
	return (CDr20_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr20_2View ���b�Z�[�W �n���h��
/*
 * -------------------------------------
 *      �����T���@�i�����������Łj     *
 * -------------------------------------
 */

#include "mfcform.h"

#define N 10       /* �f�[�^���@*/

void CDr20_2View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct girl {
        char name[12];
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i,flag=0;
	tinit();cls();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
    for (i=0;i<N;i++){
        if (strcmp(key,a[i].name)==0){
            printf("%s %d\n",a[i].name,a[i].age);
            flag=1;
            break;
        }
    }
    if (flag!=1)
        printf("������܂���ł���\n");
	tfin();
}
