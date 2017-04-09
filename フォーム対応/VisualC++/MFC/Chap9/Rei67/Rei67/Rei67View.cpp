// Rei67View.cpp : CRei67View クラスの実装
//

#include "stdafx.h"
#include "Rei67.h"

#include "Rei67Doc.h"
#include "Rei67View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei67View

IMPLEMENT_DYNCREATE(CRei67View, CFormView)

BEGIN_MESSAGE_MAP(CRei67View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei67View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei67View コンストラクション/デストラクション

CRei67View::CRei67View()
	: CFormView(CRei67View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei67View::~CRei67View()
{
}

void CRei67View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei67View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei67View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei67View 診断

#ifdef _DEBUG
void CRei67View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei67View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei67Doc* CRei67View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei67Doc)));
	return (CRei67Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei67View メッセージ ハンドラ
/*
 * -------------------------------------------------------
 *   ダイナミック・プログラミング（ナップ・サック問題）  *
 * -------------------------------------------------------
 */

#include "mfcform.h"

#define limit 8         /* ナップサックの重量制限値 */
#define n 5             /* 品物の種類 */
#define min    1        /* 重さの最小値 */

void CRei67View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct body {
        char name[20];         /* 品名 */
        int size;           /* 重さ */
        long price;         /* 価格 */
    } a[]={{"plum",4,4500},{"apple",5,5700},{"orange",2,2250},
           {"strawberry",1,1100},{"melon",6,6700}};
    long newvalue,value[limit+1];
    int item[limit+1],
        i,s,p;

    for (s=0;s<=limit;s++){
        value[s]=0;         /* 初期値 */
    }
    for (i=0;i<n;i++){                      /* 品物の番号 */
        for (s=a[i].size;s<=limit;s++){     /* ナップのサイズ */
            p=s-a[i].size;                  /* 空きサイズ */
            newvalue=value[p]+a[i].price;
            if (newvalue>value[s]){
                value[s]=newvalue;item[s]=i;    /* 最適解の更新 */
            }
        }
    }
	tinit();cls();
    printf("    品  目　価格\n");
    for (s=limit;s>=min;s=s-a[item[s]].size)
        printf("%10s %5ld\n",a[item[s]].name,a[item[s]].price);
    printf("    合  計 %5ld\n",value[limit]);
	tfin();
}
