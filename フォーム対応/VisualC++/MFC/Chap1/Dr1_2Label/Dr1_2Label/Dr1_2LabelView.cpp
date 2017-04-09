// Dr1_2LabelView.cpp : CDr1_2LabelView �N���X�̎���
//

#include "stdafx.h"
#include "Dr1_2Label.h"

#include "Dr1_2LabelDoc.h"
#include "Dr1_2LabelView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr1_2LabelView

IMPLEMENT_DYNCREATE(CDr1_2LabelView, CFormView)

BEGIN_MESSAGE_MAP(CDr1_2LabelView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr1_2LabelView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr1_2LabelView �R���X�g���N�V����/�f�X�g���N�V����

CDr1_2LabelView::CDr1_2LabelView()
	: CFormView(CDr1_2LabelView::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr1_2LabelView::~CDr1_2LabelView()
{
}

void CDr1_2LabelView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr1_2LabelView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr1_2LabelView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr1_2LabelView �f�f

#ifdef _DEBUG
void CDr1_2LabelView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr1_2LabelView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr1_2LabelDoc* CDr1_2LabelView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr1_2LabelDoc)));
	return (CDr1_2LabelDoc*)m_pDocument;
}
#endif //_DEBUG


// CDr1_2LabelView ���b�Z�[�W �n���h��
/*
 * --------------------------------
 *      �o�����������̎O�p�`      *
 * --------------------------------
 */
CStatic *Lab;		// ���x���i�X�^�e�B�b�N�e�L�X�g�j
CString cbuf,		//�����ϊ��p			
        outstr;		//�P�s�o�͗p

#define N 12
long combi(int n,int r)
{
    int i;
    long p=1;

    for (i=1;i<=r;i++)
        p=p*(n-i+1)/i;
    return p;
}

void CDr1_2LabelView::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	Lab=(CStatic *)GetDlgItem(IDC_LABEL1);
	int n,r,t;
	outstr="";
    for (n=0;n<=N;n++){
        for (t=0;t<(N-n)*3;t++)        /* �� */
            outstr+=CString(" ");
		for (r=0;r<=n;r++){
            cbuf.Format(CString("%3ld   "),combi(n,r));
			outstr+=cbuf;
		}
        outstr+=CString("\n");
    }
	Lab->SetWindowText(outstr);
}
