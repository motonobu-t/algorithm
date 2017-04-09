// Rei61View.cpp : CRei61View クラスの実装
//

#include "stdafx.h"
#include "Rei61.h"

#include "Rei61Doc.h"
#include "Rei61View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei61View

IMPLEMENT_DYNCREATE(CRei61View, CFormView)

BEGIN_MESSAGE_MAP(CRei61View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei61View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei61View コンストラクション/デストラクション

CRei61View::CRei61View()
	: CFormView(CRei61View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei61View::~CRei61View()
{
}

void CRei61View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei61View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei61View 診断

#ifdef _DEBUG
void CRei61View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei61View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei61Doc* CRei61View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei61Doc)));
	return (CRei61Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei61View メッセージ ハンドラ
/*
 * --------------------
 *     ３次元関数     *
 * --------------------
 */

#include "mfcform.h"
void CRei61View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double x,y,z,px,py,ax,ay,rd=3.1415927/180;
    ax=30*rd;
    ay=-30*rd;

    ginit(); cls();
    window(-320,-200,320,200);

    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x=x+5.0){
        y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
        px=x*cos(ay)+z*sin(ay);        /* 回転変換 */
        py=y*cos(ax)-(-x*sin(ay)+z*cos(ay))*sin(ax);
        if ((int)x==-200)
            setpoint(px,py);
        else
            moveto(px,py);
        }
    }
}
