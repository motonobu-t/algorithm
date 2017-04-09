// Dr32View.cpp : CDr32View �N���X�̎���
//

#include "stdafx.h"
#include "Dr32.h"

#include "Dr32Doc.h"
#include "Dr32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr32View

IMPLEMENT_DYNCREATE(CDr32View, CFormView)

BEGIN_MESSAGE_MAP(CDr32View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr32View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr32View �R���X�g���N�V����/�f�X�g���N�V����

CDr32View::CDr32View()
	: CFormView(CDr32View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr32View::~CDr32View()
{
}

void CDr32View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr32View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr32View �f�f

#ifdef _DEBUG
void CDr32View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr32View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr32Doc* CDr32View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr32Doc)));
	return (CDr32Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr32View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------------
 *      �n�m�C�̓��i�V�~�����|�V�����t���j     *
 * ---------------------------------------------
 */

#include "mfcform.h"

int pie[20][3];        /* 20:�~�Ղ̍ő喇��, 3:�_�̐� */
int sp[3],N;           /* �X�^�b�N�E�|�C���^ */

void move(int n,int s,int d)        /* �~�Ղ̈ړ��V�~�����[�V���� */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* ���|�����։~�Ղ̈ړ� */
    sp[d]++;                        /* �X�^�b�N�E�|�C���^�̍X�V */
    sp[s]--;

	printf("\n"); 
	printf("%d �Ԃ̉~�Ղ� %c-->%c �Ɉڂ�\n",n,'a'+s,'a'+d);
	printf("\n");   
	for (i=N-1;i>=0;i--){
        for (j=0;j<3;j++){
            if (i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
	printf("\n");
    printf("       a       b       c\n");
	AfxMessageBox(CString("���̈ړ�"),MB_OK); // ���̕\���܂ő҂�
	cls();

}
void hanoi(int n,int a,int b,int c)  /* �ċA�葱 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void CDr32View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int i;
	CString buf;
	text1.GetWindowText(buf);
	N=stoi(buf);

    for (i=0;i<N;i++)               /* �_���ɉ~�Ղ�ς� */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* �X�^�b�N�E�|�C���^�̏����ݒ� */
	tinit();cls();
    hanoi(N,0,1,2);
	tfin();
}
