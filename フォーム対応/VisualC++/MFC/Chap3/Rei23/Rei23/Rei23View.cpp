// Rei23View.cpp : CRei23View �N���X�̎���
//

#include "stdafx.h"
#include "Rei23.h"

#include "Rei23Doc.h"
#include "Rei23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei23View

IMPLEMENT_DYNCREATE(CRei23View, CFormView)

BEGIN_MESSAGE_MAP(CRei23View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei23View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei23View �R���X�g���N�V����/�f�X�g���N�V����

CRei23View::CRei23View()
	: CFormView(CRei23View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei23View::~CRei23View()
{
}

void CRei23View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei23View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei23View �f�f

#ifdef _DEBUG
void CRei23View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei23View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei23Doc* CRei23View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei23Doc)));
	return (CRei23Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei23View ���b�Z�[�W �n���h��
/*
 * -------------------------------------
 *      ������̏ƍ��i�P���ȕ��@�j     *
 * -------------------------------------
 */

#include "mfcform.h"

char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++){
        if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}
void CRei23View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";
	tinit();cls();
    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }
	tfin();
}
