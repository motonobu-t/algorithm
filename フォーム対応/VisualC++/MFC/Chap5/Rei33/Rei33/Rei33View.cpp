// Rei33View.cpp : CRei33View �N���X�̎���
//

#include "stdafx.h"
#include "Rei33.h"

#include "Rei33Doc.h"
#include "Rei33View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei33View

IMPLEMENT_DYNCREATE(CRei33View, CFormView)

BEGIN_MESSAGE_MAP(CRei33View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei33View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei33View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei33View �R���X�g���N�V����/�f�X�g���N�V����

CRei33View::CRei33View()
	: CFormView(CRei33View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei33View::~CRei33View()
{
}

void CRei33View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei33View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei33View �f�f

#ifdef _DEBUG
void CRei33View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei33View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei33Doc* CRei33View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei33Doc)));
	return (CRei33Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei33View ���b�Z�[�W �n���h��
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
int queuein(int n)       /* �L���[�Ƀf�[�^������葱�� */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;       /* �L���[����t�̂Ƃ� */
}
int queueout(int *n)     /* �L���[����f�[�^�����o���葱�� */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;       /* �L���[����̂Ƃ� */
}

void CRei33View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
	if (queuein(n)==-1){
        printf("�҂��s�񂪈�t�ł�\n");
    }
	tfin();
}

void CRei33View::OnBnClickedButton2()
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
