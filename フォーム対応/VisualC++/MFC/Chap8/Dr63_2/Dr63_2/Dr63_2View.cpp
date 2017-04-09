// Dr63_2View.cpp : CDr63_2View クラスの実装
//

#include "stdafx.h"
#include "Dr63_2.h"

#include "Dr63_2Doc.h"
#include "Dr63_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_2View

IMPLEMENT_DYNCREATE(CDr63_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_2View コンストラクション/デストラクション

CDr63_2View::CDr63_2View()
	: CFormView(CDr63_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr63_2View::~CDr63_2View()
{
}

void CDr63_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr63_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_2View 診断

#ifdef _DEBUG
void CDr63_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_2Doc* CDr63_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_2Doc)));
	return (CDr63_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_2View メッセージ ハンドラ
/*
 * -----------------
 *      Ｃ曲線     *
 * -----------------
 */

#include "mfcform.h"
void ccurve(int n)
{
    if (n==0){
        move(5);
    }
    else {
        ccurve(n-1);
        turn(90);
        ccurve(n-1);
        turn(-90);
    }
}

void CDr63_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n=10;       /* 次数 */

    ginit(); cls();

    setpoint(200,100);
    ccurve(n);
}
