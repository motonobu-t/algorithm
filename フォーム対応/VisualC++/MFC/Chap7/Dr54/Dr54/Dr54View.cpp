// Dr54View.cpp : CDr54View �N���X�̎���
//

#include "stdafx.h"
#include "Dr54.h"

#include "Dr54Doc.h"
#include "Dr54View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr54View

IMPLEMENT_DYNCREATE(CDr54View, CFormView)

BEGIN_MESSAGE_MAP(CDr54View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr54View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr54View �R���X�g���N�V����/�f�X�g���N�V����

CDr54View::CDr54View()
	: CFormView(CDr54View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr54View::~CDr54View()
{
}

void CDr54View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr54View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr54View �f�f

#ifdef _DEBUG
void CDr54View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr54View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr54Doc* CDr54View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr54Doc)));
	return (CDr54Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr54View ���b�Z�[�W �n���h��
/*
 * -----------------------------------------------
 *      �d���������̈�M�����i�L���O���t�Łj     *
 * -----------------------------------------------
 */

#include "mfcform.h"

#define Node 4        /* �ߓ_�̐� */
#define Root 6        /* �ӂ̐� */
#define Start 1       /* �J�n�_ */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,0},
                       {0,0,0,1,1},
                       {0,0,0,0,1},
                       {0,1,1,0,0}};
int success,
    v[Root+1],      /* �o�H������X�^�b�N */
    n;              /* �ʉ߂������̐� */
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){     /* �ӂ̐������ʉ߂����ɖ߂����� */
        printf("�� %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--;     /* �ʂ�����؂藣�� */
                n--;
                visit(j);
                a[i][j]++;     /* ���𕜋����� */
                n++;
            }
    }
}

void CDr54View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	tinit();cls(); 
	success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("���Ȃ�\n");
	tfin();
}
