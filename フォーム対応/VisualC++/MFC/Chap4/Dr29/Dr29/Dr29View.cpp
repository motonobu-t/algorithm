// Dr29View.cpp : CDr29View クラスの実装
//

#include "stdafx.h"
#include "Dr29.h"

#include "Dr29Doc.h"
#include "Dr29View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr29View

IMPLEMENT_DYNCREATE(CDr29View, CFormView)

BEGIN_MESSAGE_MAP(CDr29View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr29View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr29View コンストラクション/デストラクション

CDr29View::CDr29View()
	: CFormView(CDr29View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr29View::~CDr29View()
{
}

void CDr29View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr29View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr29View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr29View 診断

#ifdef _DEBUG
void CDr29View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr29View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr29Doc* CDr29View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr29Doc)));
	return (CDr29Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr29View メッセージ ハンドラ
/*
 * ------------------------------------------
 *      ハノイの塔（引数を１つ減らす）      *
 * ------------------------------------------
 */

#include "mfcform.h"

#define Total 'a'+'b'+'c'
void hanoi(int n,char a,char b)  /* 再帰手続 */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d番の円盤を %c から %c に移動\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}

void CDr29View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
    hanoi(n,'a','b');
	tfin();
}
