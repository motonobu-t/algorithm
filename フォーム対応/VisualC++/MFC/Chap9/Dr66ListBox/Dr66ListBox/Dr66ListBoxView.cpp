// Dr66ListBoxView.cpp : CDr66ListBoxView �N���X�̎���
//

#include "stdafx.h"
#include "Dr66ListBox.h"

#include "Dr66ListBoxDoc.h"
#include "Dr66ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66ListBoxView

IMPLEMENT_DYNCREATE(CDr66ListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CDr66ListBoxView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr66ListBoxView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr66ListBoxView �R���X�g���N�V����/�f�X�g���N�V����

CDr66ListBoxView::CDr66ListBoxView()
	: CFormView(CDr66ListBoxView::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr66ListBoxView::~CDr66ListBoxView()
{
}

void CDr66ListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr66ListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr66ListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr66ListBoxView �f�f

#ifdef _DEBUG
void CDr66ListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr66ListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr66ListBoxDoc* CDr66ListBoxView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr66ListBoxDoc)));
	return (CDr66ListBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CDr66ListBoxView ���b�Z�[�W �n���h��
/*
 * -------------------------
 *      �R�m�����̖��     *
 * -------------------------
 */

#define N 5

int m[N+4][N+4],                    /* �Ֆ� */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* �R�m�̈ړ������� */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* �R�m�̈ړ������� */

CListBox *LB;		// ���X�g�{�b�N�X
CString cbuf,		//	�����ϊ��p			
        outstr;		//�@�P�s�o�͗p

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* �K�⏇�Ԃ̋L�^ */
        if (count==N*N){
            outstr.Format(CString("��%3d"),++num);    /* ���̕\�� */
			LB->InsertString(-1,outstr);
            for (i=2;i<=N+1;i++){
				outstr="";
				for (j=2;j<=N+1;j++){
                    cbuf.Format(CString("%4d"),m[i][j]);
					outstr+=cbuf;
				}
				LB->InsertString(-1,outstr);
            }
        }
        else
            for (k=0;k<8;k++)           /* �i�ވʒu��I�� */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* �P�O�ɖ߂� */
        count--;
    }
}

void CDr66ListBoxView::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	LB=(CListBox *)GetDlgItem(IDC_LIST1);	// ���X�g�{�b�N�X�̎擾
	int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* �Ֆ� */
            else
                m[i][j]=1;      /* �� */

    backtrack(2,2);
}
