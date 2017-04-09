// Dr67View.cpp : CDr67View �N���X�̎���
//

#include "stdafx.h"
#include "Dr67.h"

#include "Dr67Doc.h"
#include "Dr67View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr67View

IMPLEMENT_DYNCREATE(CDr67View, CFormView)

BEGIN_MESSAGE_MAP(CDr67View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr67View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr67View �R���X�g���N�V����/�f�X�g���N�V����

CDr67View::CDr67View()
	: CFormView(CDr67View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr67View::~CDr67View()
{
}

void CDr67View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr67View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr67View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr67View �f�f

#ifdef _DEBUG
void CDr67View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr67View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr67Doc* CDr67View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr67Doc)));
	return (CDr67Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr67View ���b�Z�[�W �n���h��
/*
 * --------------------------------------------------------
 *   �_�C�i�~�b�N�E�v�O���~���O�i�ޑK�̖������ŏ��ɂ���j *
 * --------------------------------------------------------
 */

#include "mfcform.h"

#define limit 42    /* �ޑK���z */
#define n 3         /* �R�C���̎�� */

void CDr67View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int size[]={1,10,25};
    int value[limit+1],     /* ���� */
        item[limit+1],      /* �R�C���̔ԍ� */
        i,s,p,newvalue;

    for (s=0;s<=limit;s++){
        value[s]=s;          /* �����l */
    }
    for (i=0;i<n;i++){                    /* �R�C���̔ԍ� */
        for (s=size[i];s<=limit;s++){     /* �i�b�v�̃T�C�Y */
            p=s-size[i];
            newvalue=value[p]+1;
            if (newvalue<=value[s]){
                value[s]=newvalue;item[s]=i;     /* �œK���̍X�V */
            }
        }
    }
	tinit();cls();
    printf("�R�C���̖��� =%3d : ",value[limit]);
    for (s=limit;s>0;s=s-size[item[s]])
        printf("%3d,",size[item[s]]);
    printf("\n");
	tfin();
}
