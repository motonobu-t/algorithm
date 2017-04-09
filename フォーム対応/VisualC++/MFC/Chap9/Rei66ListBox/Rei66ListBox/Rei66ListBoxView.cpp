// Rei66ListBoxView.cpp : CRei66ListBoxView �N���X�̎���
//

#include "stdafx.h"
#include "Rei66ListBox.h"

#include "Rei66ListBoxDoc.h"
#include "Rei66ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66ListBoxView

IMPLEMENT_DYNCREATE(CRei66ListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CRei66ListBoxView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei66ListBoxView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei66ListBoxView �R���X�g���N�V����/�f�X�g���N�V����

CRei66ListBoxView::CRei66ListBoxView()
	: CFormView(CRei66ListBoxView::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei66ListBoxView::~CRei66ListBoxView()
{
}

void CRei66ListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}

BOOL CRei66ListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei66ListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei66ListBoxView �f�f

#ifdef _DEBUG
void CRei66ListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei66ListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei66ListBoxDoc* CRei66ListBoxView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei66ListBoxDoc)));
	return (CRei66ListBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CRei66ListBoxView ���b�Z�[�W �n���h��
/*
 * -----------------------------------------
 *      �����܁i�W�p�����������j�̖��     *
 * -----------------------------------------
 */

#define N 8
int column[N+1],    /* �������ɉ��܂��u����Ă��邩��\��*/
    rup[2*N+1],     /* �E�オ��̑Ίp����ɒu����Ă��邩��\�� */
    lup[2*N+1],     /* ���オ��̑Ίp����ɒu����Ă��邩��\�� */
    queen[N+1];     /* ���܂̈ʒu */

CListBox *LB;		// ���X�g�{�b�N�X
CString cbuf,		//	�����ϊ��p			
        outstr;		//�@�P�s�o�͗p

void backtrack(int i)
{
    int j,x,y;
    static int num=0;

    if (i>N){
		outstr.Format(CString("��%3d"),++num);    /* ���̕\�� */
		LB->InsertString(-1,outstr);  // AddString�ł͂��܂������Ȃ�
		for (y=1;y<=N;y++){
			outstr="";
			for (x=1;x<=N;x++){
				if (queen[y]==x){
					outstr+=" Q";
				}
				else{
					outstr+=" .";
				}
			}
			LB->InsertString(-1,outstr); // AddString�ł͂��܂������Ȃ�
		}
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                /* �i���C���j�����܂̈ʒu */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* �ǖʂ̕ύX */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* �ǖʂ̖߂� */
            }
        }
    }
}

void CRei66ListBoxView::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	LB=(CListBox *)GetDlgItem(IDC_LIST1);	// ���X�g�{�b�N�X�̎擾
	int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
    backtrack(1);
}
