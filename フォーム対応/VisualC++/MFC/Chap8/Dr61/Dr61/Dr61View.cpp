// Dr61View.cpp : CDr61View クラスの実装
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

// CDr61View コンストラクション/デストラクション

CDr61View::CDr61View()
	: CFormView(CDr61View::IDD)
{
	// TODO: 構築コードをここに追加します。

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
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr61View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr61View 診断

#ifdef _DEBUG
void CDr61View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr61View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr61Doc* CDr61View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr61Doc)));
	return (CDr61Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr61View メッセージ ハンドラ
/*
 * --------------------------------
 *      ３次元関数の陰線処理      *
 * --------------------------------
 */

#include "mfcform.h"

void CDr61View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int ymin[640],ymax[640];
    int k,px,py;
    double cos_x,sin_x,cos_y,sin_y,x,y,z,rd=3.1415927/180;

    ginit(); cls();
    for (k=0;k<640;k++){        /* 最大・最小判定配列 */
        ymin[k]=399;ymax[k]=0;
    }
    cos_x=cos(30*rd);  sin_x=sin(30*rd);
    cos_y=cos(-30*rd); sin_y=sin(-30*rd);
    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x++){
            y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
            px=(int)(x*cos_y+z*sin_y+320);              /* 回転変換 */
            py=(int)(y*cos_x-(-x*sin_y+z*cos_y)*sin_x+200);
            if (py<ymin[px]){               /* 今までの最小より小さい */
                ymin[px]=py;pset(px,py);
            }
            if (py>ymax[px]){               /* 今までの最大より大きい */
                ymax[px]=py;pset(px,py);
            }
        }
    }
}
