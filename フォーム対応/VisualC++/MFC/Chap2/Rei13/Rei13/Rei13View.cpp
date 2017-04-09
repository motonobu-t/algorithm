// Rei13View.cpp : CRei13View クラスの実装
//

#include "stdafx.h"
#include "Rei13.h"

#include "Rei13Doc.h"
#include "Rei13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei13View

IMPLEMENT_DYNCREATE(CRei13View, CFormView)

BEGIN_MESSAGE_MAP(CRei13View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei13View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CRei13View::OnStnClickedPict)
END_MESSAGE_MAP()

// CRei13View コンストラクション/デストラクション

CRei13View::CRei13View()
	: CFormView(CRei13View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei13View::~CRei13View()
{
}

void CRei13View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei13View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei13View 診断

#ifdef _DEBUG
void CRei13View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei13View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei13Doc* CRei13View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei13Doc)));
	return (CRei13Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei13View メッセージ ハンドラ
/*
 * -------------------
 *      多桁計算     *
 * -------------------
 */

#include "mfcform.h"

#define KETA 20             /* 桁数 */
#define N ((KETA-1)/4+1)    /* 配列サイズ */
void ladd(short a[],short b[],short c[])  /* ロング数＋ロング数 */
{
    short i,cy=0;
    for (i=N-1;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])  /* ロング数－ロング数 */
{
    short i,brrw=0;
    for (i=N-1;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void print(short c[])        /* ロング数の表示 */
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}

void CRei13View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    short a[N+2]={1999,4444,7777,2222,9999},
          b[N+2]={ 111,6666,3333,8888,1111},
          c[N+2];
	tinit();cls();
    ladd(a,b,c); print(c);
    lsub(a,b,c); print(c);
	tfin();
}

