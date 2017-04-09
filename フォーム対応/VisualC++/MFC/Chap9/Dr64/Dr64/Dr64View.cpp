// Dr64View.cpp : CDr64View クラスの実装
//

#include "stdafx.h"
#include "Dr64.h"

#include "Dr64Doc.h"
#include "Dr64View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr64View

IMPLEMENT_DYNCREATE(CDr64View, CFormView)

BEGIN_MESSAGE_MAP(CDr64View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr64View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr64View コンストラクション/デストラクション

CDr64View::CDr64View()
	: CFormView(CDr64View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr64View::~CDr64View()
{
}

void CDr64View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr64View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr64View 診断

#ifdef _DEBUG
void CDr64View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr64View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr64Doc* CDr64View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr64Doc)));
	return (CDr64Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr64View メッセージ ハンドラ
/*
 * ---------------------
 *      ４Ｎ魔方陣     *
 * ---------------------
 */

#include "mfcform.h"

#define N 8     /* ４Ｎ方陣(n=4,8,12,16,･･･) */

void CDr64View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int hojin[N+1][N+1],i,j;
	tinit();cls();
    for (j=1;j<=N;j++){
        for (i=1;i<=N;i++){
            if (j%4==i%4 || (j%4+i%4)%4==1)
                hojin[i][j]=(N+1-i)*N-j+1;
            else
                hojin[i][j]=(i-1)*N+j;
        }
    }

    printf("        ４Ｎ魔方陣 (N=%d)\n",N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++)
            printf("%4d",hojin[i][j]);
        printf("\n");
    }
	tfin();
}
