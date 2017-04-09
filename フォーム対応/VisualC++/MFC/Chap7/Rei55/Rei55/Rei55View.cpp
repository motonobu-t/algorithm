// Rei55View.cpp : CRei55View �N���X�̎���
//

#include "stdafx.h"
#include "Rei55.h"

#include "Rei55Doc.h"
#include "Rei55View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei55View

IMPLEMENT_DYNCREATE(CRei55View, CFormView)

BEGIN_MESSAGE_MAP(CRei55View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei55View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei55View �R���X�g���N�V����/�f�X�g���N�V����

CRei55View::CRei55View()
	: CFormView(CRei55View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei55View::~CRei55View()
{
}

void CRei55View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei55View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei55View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei55View �f�f

#ifdef _DEBUG
void CRei55View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei55View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei55Doc* CRei55View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei55Doc)));
	return (CRei55Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei55View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      �ŒZ�H���i�_�C�N�X�g���@�j     *
 * ---------------------------------------
 */

#include "mfcform.h"

#define N 8         /* �ߓ_�̐� */
#define M 9999

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0}, /* �אڍs�� */
                 {0,0,1,7,2,M,M,M,M},
                 {0,1,0,M,M,2,4,M,M},
                 {0,7,M,0,M,M,2,3,M},
                 {0,2,M,M,0,M,M,5,M},
                 {0,M,2,M,M,0,1,M,M},
                 {0,M,4,2,M,1,0,M,6},
                 {0,M,M,3,5,M,M,0,2},
                 {0,M,M,M,M,M,6,2,0}};
void CRei55View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int j,k,p,start,min,
        leng[N+1],              /* �ߓ_�܂ł̋��� */
        v[N+1];                 /* �m��t���O */
	tinit();cls();
	CString buf;
	text1.GetWindowText(buf);
	start=stoi(buf);

    for (k=1;k<=N;k++){
        leng[k]=M;v[k]=0;
    }
    leng[start]=0;

    for (j=1;j<=N;j++){
        min=M;          /* �ŏ��̐ߓ_��{�� */
        for (k=1;k<=N;k++){
            if (v[k]==0 && leng[k]<min){
                p=k; min=leng[k];
            }
        }
        v[p]=1;            /* �ŏ��̐ߓ_���m�肷�� */

        if (min==M){
            printf("�O���t�͘A���łȂ�\n");
            exit(1);
        }

        /* �����o�R���Ă��Ɏ��钷��������܂ł̍ŒZ�H��菬������΍X�V */
        for (k=1;k<=N;k++){
            if((leng[p]+a[p][k])<leng[k])
                leng[k]=leng[p]+a[p][k];
        }
    }
    for (j=1;j<=N;j++)
        printf("%d -> %d : %d\n",start,j,leng[j]);
	tfin();
}
