// Dr24View.cpp : CDr24View �N���X�̎���
//

#include "stdafx.h"
#include "Dr24.h"

#include "Dr24Doc.h"
#include "Dr24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr24View

IMPLEMENT_DYNCREATE(CDr24View, CFormView)

BEGIN_MESSAGE_MAP(CDr24View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr24View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr24View �R���X�g���N�V����/�f�X�g���N�V����

CDr24View::CDr24View()
	: CFormView(CDr24View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr24View::~CDr24View()
{
}

void CDr24View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr24View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr24View �f�f

#ifdef _DEBUG
void CDr24View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr24View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr24Doc* CDr24View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr24Doc)));
	return (CDr24Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr24View ���b�Z�[�W �n���h��
/*
 * ----------------------------------------
 *     ������̒u�������i���v���C�X�j     *
 * ----------------------------------------
 */

#include "mfcform.h"
char *search(char *text,char *key)  // ���̊֐����ɒu��
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
void replace(char *text,char *key,char *rep)
{
    char *p,buf[128];

    p=search(text,key);
    while (p!=NULL){
        *p='\0';
        strcpy_s(buf,128,p+strlen(key));
        strcat_s(text,128,rep);
        strcat_s(text,128,buf);
        p=search(p+strlen(rep),key);
    }
}


void CDr24View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int k;
    static char text[][128]={"     --- �T���r�A�̉� ---",
                             "���������v���Ă�",
                             "�T���r�A�̉Ԃ����Ȃ��̕����̒���",
                             "�������ꂽ����",
                             "�����ČN�̃x�b�h��",
                             "�T���r�A�̍g���Ԃ����߂�",
                             "�l�͌N�����ʂ܂ŕ������߂Ă��悤��",
                             ""};
	tinit();cls();
    k=0;
    while (text[k][0]!='\0'){
        replace(text[k],"�T���r�A","�� �� �� ��");
        replace(text[k],"�g","��");
        printf("%s\n",text[k]);
        k++;
    }
	tfin();
}
