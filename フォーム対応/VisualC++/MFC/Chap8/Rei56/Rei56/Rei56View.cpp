// Rei56View.cpp : CRei56View クラスの実装
//

#include "stdafx.h"
#include "Rei56.h"

#include "Rei56Doc.h"
#include "Rei56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei56View

IMPLEMENT_DYNCREATE(CRei56View, CFormView)

BEGIN_MESSAGE_MAP(CRei56View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei56View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei56View コンストラクション/デストラクション

CRei56View::CRei56View()
	: CFormView(CRei56View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei56View::~CRei56View()
{
}

void CRei56View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei56View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei56View 診断

#ifdef _DEBUG
void CRei56View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei56View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei56Doc* CRei56View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei56Doc)));
	return (CRei56Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei56View メッセージ ハンドラ
/*
 * -------------------------------
 *      正Ｎ角形（ポリゴン）     *
 * -------------------------------
 */

#include "mfcform.h"
void CRei56View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int j,n;

    ginit();cls();

    for (n=3;n<=9;n++){
        setpoint(200,50);
        setangle(0);
        for (j=0;j<n;j++){
            move(80);
            turn(360/n);
        }
    }
}
