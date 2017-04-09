// Dr56View.cpp : CDr56View クラスの実装
//

#include "stdafx.h"
#include "Dr56.h"

#include "Dr56Doc.h"
#include "Dr56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr56View

IMPLEMENT_DYNCREATE(CDr56View, CFormView)

BEGIN_MESSAGE_MAP(CDr56View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr56View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr56View コンストラクション/デストラクション

CDr56View::CDr56View()
	: CFormView(CDr56View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr56View::~CDr56View()
{
}

void CDr56View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr56View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr56View 診断

#ifdef _DEBUG
void CDr56View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr56View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr56Doc* CDr56View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr56Doc)));
	return (CDr56Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr56View メッセージ ハンドラ
/*
 * ----------------------
 *      渦巻き模様      *
 * ----------------------
 */

#include "mfcform.h"

void CDr56View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double leng=200.0,    /* 辺の初期値 */
           angle=89.0,    /* 回転角 */
           step=1.0;      /* 辺の減少値 */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}
