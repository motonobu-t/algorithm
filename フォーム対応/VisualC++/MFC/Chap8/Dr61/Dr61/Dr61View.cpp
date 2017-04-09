// Dr61View.cpp : CDr61View �N���X�̎���
//

#include "stdafx.h"
#include "Dr61.h"

#include "Dr61Doc.h"
#include "Dr61View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr61View

IMPLEMENT_DYNCREATE(CDr61View, CFormView)

BEGIN_MESSAGE_MAP(CDr61View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr61View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr61View �R���X�g���N�V����/�f�X�g���N�V����

CDr61View::CDr61View()
	: CFormView(CDr61View::IDD)
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B

}

CDr61View::~CDr61View()
{
}

void CDr61View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CFormView::PreCreateWindow(cs);
}

void CDr61View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr61View �f�f

#ifdef _DEBUG
void CDr61View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr61View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr61Doc* CDr61View::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr61Doc)));
	return (CDr61Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr61View ���b�Z�[�W �n���h��
/*
 * --------------------------------
 *      �R�����֐��̉A������      *
 * --------------------------------
 */

#include "mfcform.h"

void CDr61View::OnBnClickedButton1()
{
	// TODO: �����ɃR���g���[���ʒm�n���h�� �R�[�h��ǉ����܂��B
    int ymin[640],ymax[640];
    int k,px,py;
    double cos_x,sin_x,cos_y,sin_y,x,y,z,rd=3.1415927/180;

    ginit(); cls();
    for (k=0;k<640;k++){        /* �ő�E�ŏ�����z�� */
        ymin[k]=399;ymax[k]=0;
    }
    cos_x=cos(30*rd);  sin_x=sin(30*rd);
    cos_y=cos(-30*rd); sin_y=sin(-30*rd);
    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x++){
            y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
            px=(int)(x*cos_y+z*sin_y+320);              /* ��]�ϊ� */
            py=(int)(y*cos_x-(-x*sin_y+z*cos_y)*sin_x+200);
            if (py<ymin[px]){               /* ���܂ł̍ŏ���菬���� */
                ymin[px]=py;pset(px,py);
            }
            if (py>ymax[px]){               /* ���܂ł̍ő���傫�� */
                ymax[px]=py;pset(px,py);
            }
        }
    }
}
