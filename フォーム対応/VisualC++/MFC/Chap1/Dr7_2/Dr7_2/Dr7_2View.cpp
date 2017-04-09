// Dr7_2View.cpp : CDr7_2View クラスの実装
//

#include "stdafx.h"
#include "Dr7_2.h"

#include "Dr7_2Doc.h"
#include "Dr7_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr7_2View

IMPLEMENT_DYNCREATE(CDr7_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr7_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr7_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr7_2View コンストラクション/デストラクション

CDr7_2View::CDr7_2View()
	: CFormView(CDr7_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr7_2View::~CDr7_2View()
{
}

void CDr7_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr7_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr7_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr7_2View 診断

#ifdef _DEBUG
void CDr7_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr7_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr7_2Doc* CDr7_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr7_2Doc)));
	return (CDr7_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr7_2View メッセージ ハンドラ
/*
 * ---------------------------------------
 *        エラトステネスのふるい         *
 * ---------------------------------------
 */

#include "mfcform.h"

#define NUM 1000
void CDr7_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int prime[NUM+1];
    int i,j,Limit;

    for (i=2;i<=NUM;i++)
        prime[i]=1;

    Limit=(int)sqrt((double)NUM);
    for (i=2;i<=Limit;i++){
        if (prime[i]==1){
            for (j=2*i;j<=NUM;j++){
                if (j%i==0)
                    prime[j]=0;
            }
        }
    }

	tinit();cls();
    printf("\n求められた素数\n");
	for (i=2;i<=NUM;i++){
		if (prime[i]==1)
            printf("%5d",i);
	}
    printf("\n");
	tfin();
}
