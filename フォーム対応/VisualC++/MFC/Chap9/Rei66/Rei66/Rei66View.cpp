// Rei66View.cpp : CRei66View クラスの実装
//

#include "stdafx.h"
#include "Rei66.h"

#include "Rei66Doc.h"
#include "Rei66View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66View

IMPLEMENT_DYNCREATE(CRei66View, CFormView)

BEGIN_MESSAGE_MAP(CRei66View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei66View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei66View コンストラクション/デストラクション

CRei66View::CRei66View()
	: CFormView(CRei66View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei66View::~CRei66View()
{
}

void CRei66View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei66View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei66View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei66View 診断

#ifdef _DEBUG
void CRei66View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei66View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei66Doc* CRei66View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei66Doc)));
	return (CRei66Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei66View メッセージ ハンドラ
/*
 * -----------------------------------------
 *      八王妃（８Ｑｕｅｅｎｓ）の問題     *
 * -----------------------------------------
 */

#include "mfcform.h"

#define N 8
int column[N+1],    /* 同じ欄に王妃が置かれているかを表す*/
    rup[2*N+1],     /* 右上がりの対角線上に置かれているかを表す */
    lup[2*N+1],     /* 左上がりの対角線上に置かれているかを表す */
    queen[N+1];     /* 王妃の位置 */

void backtrack(int i)
{
    int j,x,y;
    static int num=0;
    if (i>N){
        printf("解 %d \n",++num);        /* 解の表示 */
        for (y=1;y<=N;y++){
            for (x=1;x<=N;x++)
                if (queen[y]==x)
                    printf(" Q");
                else
                    printf(" .");
            printf("\n");
        }
		AfxMessageBox(CString("次の移動"),MB_OK);  // 次の移動まで待つ
		cls();
    }
    else {
        for (j=1;j<=N;j++) {
            if (column[j]==1 && rup[i+j]==1 && lup[i-j+N]==1){
                queen[i]=j;                /* （ｉ，ｊ）が王妃の位置 */
                column[j]=rup[i+j]=lup[i-j+N]=0;    /* 局面の変更 */
                backtrack(i+1);
                column[j]=rup[i+j]=lup[i-j+N]=1;    /* 局面の戻し */
            }
        }
    }
}

void CRei66View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
	tinit();cls();
    backtrack(1);
	tfin();
}
