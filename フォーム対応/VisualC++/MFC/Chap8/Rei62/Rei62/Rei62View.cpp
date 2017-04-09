// Rei62View.cpp : CRei62View クラスの実装
//

#include "stdafx.h"
#include "Rei62.h"

#include "Rei62Doc.h"
#include "Rei62View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei62View

IMPLEMENT_DYNCREATE(CRei62View, CFormView)

BEGIN_MESSAGE_MAP(CRei62View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei62View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei62View コンストラクション/デストラクション

CRei62View::CRei62View()
	: CFormView(CRei62View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei62View::~CRei62View()
{
}

void CRei62View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei62View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei62View 診断

#ifdef _DEBUG
void CRei62View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei62View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei62Doc* CRei62View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei62Doc)));
	return (CRei62Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei62View メッセージ ハンドラ
/*
 * -----------------------
 *       コッホ曲線      *
 * -----------------------
 */

#include "mfcform.h"
void koch(int n,double leng)        /* コッホ曲線の再帰手続き */
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}

void CRei62View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int    n=4;         /* コッホ次数 */
    double leng=4.0;    /* ０次の長さ */

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

    koch(n,leng);
}
