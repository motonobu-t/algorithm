// Dr6View.cpp : CDr6View クラスの実装
//

#include "stdafx.h"
#include "Dr6.h"

#include "Dr6Doc.h"
#include "Dr6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr6View

IMPLEMENT_DYNCREATE(CDr6View, CFormView)

BEGIN_MESSAGE_MAP(CDr6View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr6View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CDr6View::OnStnClickedPict)
END_MESSAGE_MAP()

// CDr6View コンストラクション/デストラクション

CDr6View::CDr6View()
	: CFormView(CDr6View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr6View::~CDr6View()
{
}

void CDr6View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr6View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr6View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr6View 診断

#ifdef _DEBUG
void CDr6View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr6View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr6Doc* CDr6View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr6Doc)));
	return (CDr6Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr6View メッセージ ハンドラ
/*
 * ---------------------------------
 *      ユークリッドの互除法       *
 * ---------------------------------
 */

#include "mfcform.h"

void CDr6View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a,b,m,n,k;

	CString buf;
	text1.GetWindowText(buf);
	a=stoi(buf);
	text2.GetWindowText(buf);
	b=stoi(buf);
    m=a; n=b;
    do{
        k=m % n;
        m=n; n=k;
    } while(k!=0);

	tinit();cls();
    printf("最大公約数=%d\n",m);
	tfin();
}

//void CDr6View::OnStnClickedPict()
//{
//	// TODO: ここにコントロール通知ハンドラ コードを追加します。
//}
