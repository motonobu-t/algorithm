// Rei15View.cpp : CRei15View クラスの実装
//

#include "stdafx.h"
#include "Rei15.h"

#include "Rei15Doc.h"
#include "Rei15View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei15View

IMPLEMENT_DYNCREATE(CRei15View, CFormView)

BEGIN_MESSAGE_MAP(CRei15View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei15View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei15View コンストラクション/デストラクション

CRei15View::CRei15View()
	: CFormView(CRei15View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei15View::~CRei15View()
{
}

void CRei15View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei15View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei15View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei15View 診断

#ifdef _DEBUG
void CRei15View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei15View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei15Doc* CRei15View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei15Doc)));
	return (CRei15Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei15View メッセージ ハンドラ
/*
 * ---------------------------------------------------
 *      連立方程式の解法（ガウス・ジョルダン法）     *
 * ---------------------------------------------------
 */

#include "mfcform.h"

#define N 3     /* 元の数 */
void CRei15View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double a[N][N+1]={{2.0  ,3.0  ,1.0  ,4.0  },
                      {4.0  ,1.0  ,-3.0 ,-2.0 },
                      {-1.0 ,2.0  ,2.0  ,2.0  }};
    double p,d;
    int i,j,k;

    for (k=0;k<N;k++){
        p=a[k][k];                /* ピボット係数 */
        for (j=k;j<N+1;j++)       /* ピボット行をｐで割る */
            a[k][j]=a[k][j]/p;
        for (i=0;i<N;i++){        /* ピボット列の掃き出し */
            if (i!=k){
                d=a[i][k];
                for (j=k;j<N+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

	tinit();cls();
    for (k=0;k<N;k++)
        printf("x%d=%f\n",k+1,a[k][N]);
	tfin();

}
