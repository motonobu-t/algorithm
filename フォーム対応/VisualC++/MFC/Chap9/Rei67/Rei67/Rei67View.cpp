// Rei67View.cpp : CRei67View �N���X�̎���
//

#include "stdafx.h"
#include "Rei67.h"

#include "Rei67Doc.h"
#include "Rei67View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei67View

IMPLEMENT_DYNCREATE(CRei67View, CFormView)

BEGIN_MESSAGE_MAP(CRei67View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei67View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei67View �R���X�g���N�V����/�f�X�g���N�V����

CRei67View::CRei67View()
	: CFormView(CRei67View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei67View::~CRei67View()
{
}

void CRei67View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei67View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei67View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei67View �f�f

#ifdef _DEBUG
void CRei67View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei67View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei67Doc* CRei67View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei67Doc)));
	return (CRei67Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei67View ���b�Z�[�W �n���h��
/*
 * -------------------------------------------------------
 *   �_�C�i�~�b�N�E�v���O���~���O�i�i�b�v�E�T�b�N���j  *
 * -------------------------------------------------------
 */

#include "mfcform.h"

#define limit 8         /* �i�b�v�T�b�N�̏d�ʐ����l */
#define n 5             /* �i���̎�� */
#define min    1        /* �d���̍ŏ��l */

void CRei67View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    struct body {
        char name[20];         /* �i�� */
        int size;           /* �d�� */
        long price;         /* ���i */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++){
        value[s]=0;         /* �����l */
    }
    for (i=0;i<n;i++){                      /* �i���̔ԍ� */
        for (s=a[i].size;s<=limit;s++){     /* �i�b�v�̃T�C�Y */
            p=s-a[i].size;                  /* �󂫃T�C�Y */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s]){
                value[s]=newvalue;item[s]=i;    /* �œK���̍X�V */
            }
        }
    }
	tinit();cls();
    printf("    �i  �ځ@���i\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %5ld\n",a[item[s]].name,a[item[s]].price);
    printf("    ��  �v %5ld\n",value[limit]);
	tfin();
}
