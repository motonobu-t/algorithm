// Rei27View.cpp : CRei27View クラスの実装
//

#include "stdafx.h"
#include "Rei27.h"

#include "Rei27Doc.h"
#include "Rei27View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei27View

IMPLEMENT_DYNCREATE(CRei27View, CFormView)

BEGIN_MESSAGE_MAP(CRei27View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei27View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei27View コンストラクション/デストラクション

CRei27View::CRei27View()
	: CFormView(CRei27View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei27View::~CRei27View()
{
}

void CRei27View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei27View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei27View 診断

#ifdef _DEBUG
void CRei27View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei27View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei27Doc* CRei27View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei27Doc)));
	return (CRei27Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei27View メッセージ ハンドラ
/*
 * ---------------------------
 *     階乗計算の非再帰解    *
 * ---------------------------
 */

#include "mfcform.h"
long kaijo(int n)   /* 階乗 */
{
    int k;
    long p=1L;

    for (k=n;k>=1;k--)
        p=p*k;
    return p;
}

void CRei27View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n;
	tinit();cls();
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));
	tfin();
}
