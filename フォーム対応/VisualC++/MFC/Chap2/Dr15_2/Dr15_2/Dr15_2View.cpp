// Dr15_2View.cpp : CDr15_2View クラスの実装
//

#include "stdafx.h"
#include "Dr15_2.h"

#include "Dr15_2Doc.h"
#include "Dr15_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr15_2View

IMPLEMENT_DYNCREATE(CDr15_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr15_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr15_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr15_2View コンストラクション/デストラクション

CDr15_2View::CDr15_2View()
	: CFormView(CDr15_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr15_2View::~CDr15_2View()
{
}

void CDr15_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr15_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr15_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr15_2View 診断

#ifdef _DEBUG
void CDr15_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr15_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr15_2Doc* CDr15_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr15_2Doc)));
	return (CDr15_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr15_2View メッセージ ハンドラ
/*
 * ---------------------------------------------
 *      連立方程式の解法（ガウスの消去法）     *
 * ---------------------------------------------
 */

#include "mfcform.h"

#define N 3     /* 元の数 */
void CDr15_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                      {4.0  ,1.0  ,-3.0 ,-2.0 },
                      {-1.0 ,2.0  ,2.0  ,2.0  }};
    double d;
    int i,j,k;

    for (k=0;k<N-1;k++){            /* 前進消去 */
        for (i=k+1;i<N;i++){
            d=a[i][k]/a[k][k];
            for (j=k+1;j<=N;j++)
                a[i][j]=a[i][j]-a[k][j]*d;
        }
    }
    for (i=N-1;i>=0;i--){            /* 後退代入 */
        d=a[i][N];
        for (j=i+1;j<N;j++)
            d=d-a[i][j]*a[j][N];
        a[i][N]=d/a[i][i];
    }

	tinit();cls();
    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);
	tfin();
}
