// Dr15_1View.cpp : CDr15_1View �N���X�̎���
//

#include "stdafx.h"
#include "Dr15_1.h"

#include "Dr15_1Doc.h"
#include "Dr15_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr15_1View

IMPLEMENT_DYNCREATE(CDr15_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr15_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr15_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr15_1View �R���X�g���N�V����/�f�X�g���N�V����

CDr15_1View::CDr15_1View()
	: CFormView(CDr15_1View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr15_1View::~CDr15_1View()
{
}

void CDr15_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr15_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr15_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr15_1View �f�f

#ifdef _DEBUG
void CDr15_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr15_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr15_1Doc* CDr15_1View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr15_1Doc)));
	return (CDr15_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr15_1View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------
 *      �A���������̉�@�i�s�{�b�g�I��@�j     *
 * ---------------------------------------------
 */

#include "mfcform.h"

#define N 3     /* ���̐� */
void CDr15_1View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                      {4.0  ,1.0  ,-3.0 ,-2.0 },
                      {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d,max,dumy;
    int i,j,k,s;
	tinit();cls();
    for (k=0;k<N;k++){
        max=0;s=k;
        for(j=k;j<N;j++){
            if (fabs(a[j][k])>max){
                max=fabs(a[j][k]);s=j;
            }
        }
        if (max==0){
            printf("�����Ȃ�");
            exit(1);
        }
        for (j=0;j<=N;j++){
            dumy=a[k][j];
            a[k][j]=a[s][j];
            a[s][j]=dumy;
        }

        p=a[k][k];              /* �s�{�b�g�W�� */
        for (j=k;j<N+1;j++)        /* �s�{�b�g�s�����Ŋ��� */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){      /* �s�{�b�g��̑|���o�� */
            if (i!=k){
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);
	tfin();
}
