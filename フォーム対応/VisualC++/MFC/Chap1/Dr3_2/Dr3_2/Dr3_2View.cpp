// Dr3_2View.cpp : CDr3_2View クラスの実装
//

#include "stdafx.h"
#include "Dr3_2.h"

#include "Dr3_2Doc.h"
#include "Dr3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr3_2View

IMPLEMENT_DYNCREATE(CDr3_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr3_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr3_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr3_2View コンストラクション/デストラクション

CDr3_2View::CDr3_2View()
	: CFormView(CDr3_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr3_2View::~CDr3_2View()
{
}

void CDr3_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr3_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr3_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr3_2View 診断

#ifdef _DEBUG
void CDr3_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr3_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr3_2Doc* CDr3_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr3_2Doc)));
	return (CDr3_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr3_2View メッセージ ハンドラ
/*
 * -----------------------------------
 *       順位付け（負のデータ版）    *
 * -----------------------------------
 */

#include "mfcform.h"

#define Num 10
#define Max 36
#define Min -20
#define Bias 1-(Min)    /* 最小値を配列要素の１に対応させる */

void CDr3_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={-3,2,3,-1,-2,-6,2,-1,1,5};
    int i,juni[Max+Bias+1];

	for (i=Min+Bias;i<=Max+Bias;i++)
        juni[i]=0;

    for (i=0;i<Num;i++)
        juni[a[i]+Bias]++;

    juni[0]=1;
    for (i=Min+Bias;i<=Max+Bias;i++)
        juni[i]=juni[i]+juni[i-1];

	tinit();cls();
    printf("　得点　順位\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[a[i]+Bias-1]);
    }
	tfin();
}
