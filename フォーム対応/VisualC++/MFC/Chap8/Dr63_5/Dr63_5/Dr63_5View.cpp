// Dr63_5View.cpp : CDr63_5View クラスの実装
//

#include "stdafx.h"
#include "Dr63_5.h"

#include "Dr63_5Doc.h"
#include "Dr63_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_5View

IMPLEMENT_DYNCREATE(CDr63_5View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_5View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_5View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_5View コンストラクション/デストラクション

CDr63_5View::CDr63_5View()
	: CFormView(CDr63_5View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr63_5View::~CDr63_5View()
{
}

void CDr63_5View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr63_5View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_5View 診断

#ifdef _DEBUG
void CDr63_5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_5Doc* CDr63_5View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_5Doc)));
	return (CDr63_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_5View メッセージ ハンドラ
/*
 * -------------------------------
 *      シェルピンスキー曲線     *
 * -------------------------------
 */

#include "mfcform.h"
void sierpin(int n,double l)
{
    if (n==0){
        turn(-90);
        return;
    }
    sierpin(n-1,l);move(l);
    sierpin(n-1,l);turn(135);move(l);
    turn(135);sierpin(n-1,l);move(l);
    sierpin(n-1,l);
}

void CDr63_5View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,n =3,         /* 次数 */
        leng=10;        /* 長さ */

    ginit(); cls();

    setpoint(350,300);setangle(-45);
    for (i=0;i<4;i++){
        move(leng);
        sierpin(n,leng);
    }
}
