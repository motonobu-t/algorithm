// Dr21View.cpp : CDr21View クラスの実装
//

#include "stdafx.h"
#include "Dr21.h"

#include "Dr21Doc.h"
#include "Dr21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr21View

IMPLEMENT_DYNCREATE(CDr21View, CFormView)

BEGIN_MESSAGE_MAP(CDr21View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr21View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr21View コンストラクション/デストラクション

CDr21View::CDr21View()
	: CFormView(CDr21View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr21View::~CDr21View()
{
}

void CDr21View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr21View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr21View 診断

#ifdef _DEBUG
void CDr21View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr21View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr21Doc* CDr21View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr21Doc)));
	return (CDr21Doc*)m_pDocument;
}
#endif //_DEBUG

/*
 * --------------------
 *     ２分探索法     *
 * --------------------
 */

#include "mfcform.h"

#define N 10       /* データ数　*/
// CDr21View メッセージ ハンドラ

void CDr21View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={2,3,7,11,31,50,55,70,77,80};
    int key,low,high,mid;


	CString buf;
	text1.GetWindowText(buf);
	key=stoi(buf);

    low=0;high=N-1;
    while (low<=high){
        mid=(low+high)/2;
        if (a[mid]<=key)
            low=mid+1;
        if (a[mid]>=key)
            high=mid-1;
    }

	tinit();cls();
    if (low==high+2)
        printf("%d は %d 番目にありました\n",a[mid],mid);
    else
        printf("見つかりませんでした\n");
	tfin();
}
