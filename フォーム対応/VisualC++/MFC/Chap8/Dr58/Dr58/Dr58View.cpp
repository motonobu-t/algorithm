// Dr58View.cpp : CDr58View クラスの実装
//

#include "stdafx.h"
#include "Dr58.h"

#include "Dr58Doc.h"
#include "Dr58View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr58View

IMPLEMENT_DYNCREATE(CDr58View, CFormView)

BEGIN_MESSAGE_MAP(CDr58View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr58View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr58View コンストラクション/デストラクション

CDr58View::CDr58View()
	: CFormView(CDr58View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr58View::~CDr58View()
{
}

void CDr58View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr58View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr58View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr58View 診断

#ifdef _DEBUG
void CDr58View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr58View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr58Doc* CDr58View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr58Doc)));
	return (CDr58Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr58View メッセージ ハンドラ
/*
 * -------------------
 *      √２分割     *
 * -------------------
 */

#include "mfcform.h"

void CDr58View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int k;
    double leng=400.0,            /* 対角線の初期値 */
           rd=3.14159/180,
           x,y;

    ginit(); cls();
    setpoint(0,380); setangle(-54.7);
    for (k=1;k<=10;k++){
        move(leng);                 /* 対角線を引く */
        x=leng*cos(54.7*rd);        /* ｘ方向の長さ */
        y=leng*sin(54.7*rd);        /* ｙ方向の長さ */
        turn(180-35.3); move(y);    /* 長方形を描く */
        turn(90); move(x);
        turn(90); move(y);
        turn(90); move(x);
        turn(35.3);
        leng=leng/sqrt(2.0);
    }
}
