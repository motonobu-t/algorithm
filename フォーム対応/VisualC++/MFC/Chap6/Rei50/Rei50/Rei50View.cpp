// Rei50View.cpp : CRei50View �N���X�̎���
//

#include "stdafx.h"
#include "Rei50.h"

#include "Rei50Doc.h"
#include "Rei50View.h"
#include "Input.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei50View

IMPLEMENT_DYNCREATE(CRei50View, CFormView)

BEGIN_MESSAGE_MAP(CRei50View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei50View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei50View �R���X�g���N�V����/�f�X�g���N�V����

CRei50View::CRei50View()
	: CFormView(CRei50View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CRei50View::~CRei50View()
{
}

void CRei50View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CRei50View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CRei50View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei50View �f�f

#ifdef _DEBUG
void CRei50View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei50View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei50Doc* CRei50View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei50Doc)));
	return (CRei50Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei50View ���b�Z�[�W �n���h��
/*
 * ---------------------------------------
 *      ���^�����ƌ���؁i�z��\���j     *
 * ---------------------------------------
 */

#define Max 100
#define nil -1
struct tnode {
    int left;      /* ���ւ̃|�C���^ */
    CString node;  /* CString�^�œ��� */
    int right;     /* �E�ւ̃|�C���^ */
};
struct tnode a[Max]={{1  ,CString("�|�\�l�ł���")  ,2},
                     {3  ,CString("�̎�ł���")    ,4},
                     {nil,CString("�g�c�@��")      ,nil},
                     {nil,CString("���@�z��")    ,nil},
                     {5  ,CString("���D�ł���")    ,6},
                     {nil,CString("���R�@����")    ,nil},
                     {nil,CString("�v�� �G")       ,nil}};
int lp=6;
void CRei50View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
	CInput dlg;  // ���͗p�_�C�A���O�{�b�N�X
	int p,c;
	do {
        p=0;
        while (a[p].left!=nil){          /* �؂̃T�[�` */
			c=AfxMessageBox(CString(a[p].node),MB_YESNO);
            if (c==IDYES)
                p=a[p].left;
            else
                p=a[p].right;
        }
		c=AfxMessageBox(CString(a[p].node),MB_YESNO);

        if (c==IDNO){               /* �w�K�@�\ */
            a[lp+1]=a[p];                    /* �m�[�h�̈ړ� */
                                           /* �V�����m�[�h�̍쐬 */
			dlg.m_msg="���Ȃ��̍l����";
			dlg.m_text="";
			dlg.DoModal();
			a[lp+2].node=dlg.m_text;
            a[lp+2].left=a[lp+2].right=nil;
                                            /* ����m�[�h�̍쐬 */
			dlg.m_msg=a[lp+1].node+CString("��")+a[lp+2].node+CString("����ʂ��鎿���");
			dlg.m_text="";
			dlg.DoModal();
			a[p].node=dlg.m_text;
			c=AfxMessageBox(CString("�������̍��ڂ�")+a[lp+1].node+CString("�ŗǂ��ł���"),MB_YESNO);
            if (c==IDYES){          /* �q�̐ڑ� */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
    } while (c=AfxMessageBox(CString("�����܂���"),MB_YESNO),c==IDYES);
}
