// Dr66View.cpp : CDr66View クラスの実装
//

#include "stdafx.h"
#include "Dr66.h"

#include "Dr66Doc.h"
#include "Dr66View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66View

IMPLEMENT_DYNCREATE(CDr66View, CFormView)

BEGIN_MESSAGE_MAP(CDr66View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr66View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr66View コンストラクション/デストラクション

CDr66View::CDr66View()
	: CFormView(CDr66View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr66View::~CDr66View()
{
}

void CDr66View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr66View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr66View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr66View 診断

#ifdef _DEBUG
void CDr66View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr66View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr66Doc* CDr66View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr66Doc)));
	return (CDr66Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr66View メッセージ ハンドラ
/*
 * -------------------------
 *      騎士巡歴の問題     *
 * -------------------------
 */

#include "mfcform.h"

void backtrack(int,int);

#define N 5

int m[N+4][N+4],                    /* 盤面 */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* 騎士の移動ｘ成分 */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* 騎士の移動ｙ成分 */

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* 訪問順番の記録 */
        if (count==N*N){
            printf("解%d\n",++num);    /* 解の表示 */
            for (i=2;i<=N+1;i++){
                for (j=2;j<=N+1;j++)
                    printf("%4d",m[i][j]);
                printf("\n");
            }
			AfxMessageBox(CString("次の移動"),MB_OK); // 次の移動まで待つ
			cls();
        }
        else
            for (k=0;k<8;k++)           /* 進む位置を選ぶ */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* １つ前に戻る */
        count--;
    }
}

void CDr66View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* 盤面 */
            else
                m[i][j]=1;      /* 壁 */
	tinit();cls();
    backtrack(2,2);
	tfin();
}
