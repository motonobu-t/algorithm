// Dr33View.cpp : CDr33View �N���X�̎���
//

#include "stdafx.h"
#include "Dr33.h"

#include "Dr33Doc.h"
#include "Dr33View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr33View

IMPLEMENT_DYNCREATE(CDr33View, CFormView)

BEGIN_MESSAGE_MAP(CDr33View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr33View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr33View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr33View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr33View �R���X�g���N�V����/�f�X�g���N�V����

CDr33View::CDr33View()
	: CFormView(CDr33View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr33View::~CDr33View()
{
}

void CDr33View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr33View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr33View �f�f

#ifdef _DEBUG
void CDr33View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr33View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr33Doc* CDr33View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr33Doc)));
	return (CDr33Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr33View ���b�Z�[�W �n���h��
/*
 * -----------------------------
 *      �L���[�i�҂��s��j     *
 * -----------------------------
 */

#include "mfcform.h"

#define MaxSize 100     /* �L���[�E�T�C�Y */
int queue[MaxSize];     /* �L���[ */
int head=0,             /* �擪�f�[�^�ւ̃|�C���^ */
    tail=0;             /* �I�[�f�[�^�ւ̃|�C���^ */
int queuein(int n)     /* �L���[�Ƀf�[�^������葱�� */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;      /* �L���[����t�̂Ƃ� */
}
int queueout(int *n)    /* �L���[����f�[�^�����o���葱�� */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;     /* �L���[����̂Ƃ� */
}
void disp(void)        /* �҂��s��̓��e��\������葱�� */
{
    int i;

    i=head;
    while (i!=tail){
        printf("%d\n",queue[i]);
        i++;
        i=i%MaxSize;
    }
}
void CDr33View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
	if (queuein(n)==-1)
         printf("�҂��s�񂪈�t�ł�\n");
	tfin();
}

void CDr33View::OnBnClickedButton2()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	tinit();cls();
	if (queueout(&n)==-1)
        printf("�҂��s��͋�ł�\n");
    else
        printf("queue data --> %d\n",n);
	tfin();
}

void CDr33View::OnBnClickedButton3()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls();
	disp();
	tfin();
}
