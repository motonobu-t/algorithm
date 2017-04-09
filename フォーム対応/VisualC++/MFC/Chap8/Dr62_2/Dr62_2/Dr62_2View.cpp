// Dr62_2View.cpp : CDr62_2View クラスの実装
//

#include "stdafx.h"
#include "Dr62_2.h"

#include "Dr62_2Doc.h"
#include "Dr62_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_2View

IMPLEMENT_DYNCREATE(CDr62_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr62_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr62_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr62_2View コンストラクション/デストラクション

CDr62_2View::CDr62_2View()
	: CFormView(CDr62_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr62_2View::~CDr62_2View()
{
}

void CDr62_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr62_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr62_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr62_2View 診断

#ifdef _DEBUG
void CDr62_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr62_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr62_2Doc* CDr62_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr62_2Doc)));
	return (CDr62_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr62_2View メッセージ ハンドラ
/*
 * ------------------------------
 *       クロス・ステッチ       *
 * ------------------------------
 */

#include "mfcform.h"
void stech(int n,double leng)       /* ステッチの再帰手続き */
{
    if (n==0)
        move(leng);
    else {
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng);
    }
}
void CDr62_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int    k,
           n=4;         /* ステッチの次数 */
    double leng=2.0;    /* ０次の長さ */

    ginit(); cls();
    setpoint(200,150); setangle(0);
    for (k=1;k<=4;k++){
        stech(n,leng);
        turn(90);
    }
}
