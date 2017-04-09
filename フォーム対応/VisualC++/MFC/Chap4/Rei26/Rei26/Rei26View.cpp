// Rei26View.cpp : CRei26View クラスの実装
//

#include "stdafx.h"
#include "Rei26.h"

#include "Rei26Doc.h"
#include "Rei26View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei26View

IMPLEMENT_DYNCREATE(CRei26View, CFormView)

BEGIN_MESSAGE_MAP(CRei26View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei26View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei26View コンストラクション/デストラクション

CRei26View::CRei26View()
	: CFormView(CRei26View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei26View::~CRei26View()
{
}

void CRei26View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei26View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei26View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei26View 診断

#ifdef _DEBUG
void CRei26View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei26View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei26Doc* CRei26View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei26Doc)));
	return (CRei26Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei26View メッセージ ハンドラ
/*
 * -------------------------
 *     階乗計算の再帰解    *
 * -------------------------
 */

#include "mfcform.h"
long kaijo(int n)   /* 再帰手続 */
{
    if (n==0)
        return 1L;
    else
        return n*kaijo(n-1);
}

void CRei26View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n;
	tinit();cls();
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));
	tfin();
}
