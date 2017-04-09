// Rei29View.cpp : CRei29View クラスの実装
//

#include "stdafx.h"
#include "Rei29.h"

#include "Rei29Doc.h"
#include "Rei29View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei29View

IMPLEMENT_DYNCREATE(CRei29View, CFormView)

BEGIN_MESSAGE_MAP(CRei29View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei29View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei29View コンストラクション/デストラクション

CRei29View::CRei29View()
	: CFormView(CRei29View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei29View::~CRei29View()
{
}

void CRei29View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei29View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei29View 診断

#ifdef _DEBUG
void CRei29View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei29View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei29Doc* CRei29View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei29Doc)));
	return (CRei29Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei29View メッセージ ハンドラ
/*
 * ------------------------------
 *      ハノイの塔の再帰解      *
 * ------------------------------
 */

#include "mfcform.h"
void hanoi(int n,char a,char b,char c)  /* 再帰手続 */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d番の円盤を %c から %c に移動\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void CRei29View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
    hanoi(n,'a','b','c');
	tfin();
}
