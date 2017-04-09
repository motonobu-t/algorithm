// Rei16View.cpp : CRei16View クラスの実装
//

#include "stdafx.h"
#include "Rei16.h"

#include "Rei16Doc.h"
#include "Rei16View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei16View

IMPLEMENT_DYNCREATE(CRei16View, CFormView)

BEGIN_MESSAGE_MAP(CRei16View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei16View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei16View コンストラクション/デストラクション

CRei16View::CRei16View()
	: CFormView(CRei16View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei16View::~CRei16View()
{
}

void CRei16View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei16View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei16View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei16View 診断

#ifdef _DEBUG
void CRei16View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei16View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei16Doc* CRei16View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei16Doc)));
	return (CRei16Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei16View メッセージ ハンドラ
/*
 * ---------------------------------------------------------
 *      線形計画法（Ｌｉｎｅａ　Ｐｒｏｇｒａｍｉｎｇ）     *
 * ---------------------------------------------------------
 */

#include "mfcform.h"

#define N1 4     /* 行数 */
#define N2 6     /* 列数 */
#define N3 2     /* 変数の数 */

void CRei16View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double a[N1][N2]={{1.0,2.0,1.0,0.0,0.0,14.0  },
                      {1.0,1.0,0.0,1.0,0.0,8.0   },
                      {3.0,1.0,0.0,0.0,1.0,18.0  },
                      {-2.0,-3.0,0.0,0.0,0.0,0.0}};
    double min,p,d;
    int j,k,x,y,flag;

    while (1){
        min=9999;           /* 列選択 */
        for (k=0;k<N2-1;k++){
            if (a[N1-1][k]<min){
                min=a[N1-1][k];
                y=k;
            }
        }

        if (min>=0)
            break;

        min=9999;           /* 行選択 */
        for (k=0;k<N1-1;k++){
            p=a[k][N2-1]/a[k][y];
            if (a[k][y]>0 && p<min){
                min=p;
                x=k;
            }
        }
        p=a[x][y];              /* ピボット係数 */
        for (k=0;k<N2;k++)      /* ピボット行をｐで割る */
            a[x][k]=a[x][k]/p;
        for (k=0;k<N1;k++){     /* ピボット列の掃き出し */
            if (k!=x){
                d=a[k][y];
                for (j=0;j<N2;j++)
                    a[k][j]=a[k][j]-d*a[x][j];
            }
        }
    }

	tinit();cls();
    for (k=0;k<N3;k++){
        flag=-1;
        for (j=0;j<N1;j++){
            if (a[j][k]==1)
                flag=j;
        }
        if (flag!=-1)
            printf("x%d = %f\n",k,a[flag][N2-1]);
        else
            printf("x%d = %f\n",k,0);
    }
    printf("z= %f\n",a[N1-1][N2-1]);
	tfin();
}
