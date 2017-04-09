// Dr66ListBoxView.cpp : CDr66ListBoxView クラスの実装
//

#include "stdafx.h"
#include "Dr66ListBox.h"

#include "Dr66ListBoxDoc.h"
#include "Dr66ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66ListBoxView

IMPLEMENT_DYNCREATE(CDr66ListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CDr66ListBoxView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr66ListBoxView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr66ListBoxView コンストラクション/デストラクション

CDr66ListBoxView::CDr66ListBoxView()
	: CFormView(CDr66ListBoxView::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr66ListBoxView::~CDr66ListBoxView()
{
}

void CDr66ListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr66ListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr66ListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr66ListBoxView 診断

#ifdef _DEBUG
void CDr66ListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr66ListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr66ListBoxDoc* CDr66ListBoxView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr66ListBoxDoc)));
	return (CDr66ListBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CDr66ListBoxView メッセージ ハンドラ
/*
 * -------------------------
 *      騎士巡歴の問題     *
 * -------------------------
 */

#define N 5

int m[N+4][N+4],                    /* 盤面 */
    dx[8]={2,1,-1,-2,-2,-1,1,2},    /* 騎士の移動ｘ成分 */
    dy[8]={1,2,2,1,-1,-2,-2,-1};    /* 騎士の移動ｙ成分 */

CListBox *LB;		// リストボックス
CString cbuf,		//	書式変換用			
        outstr;		//　１行出力用

void backtrack(int x,int y)
{
    int i,j,k;
    static int count=0,num=0;

    if (m[x][y]==0){
        m[x][y]=++count;         /* 訪問順番の記録 */
        if (count==N*N){
            outstr.Format(CString("解%3d"),++num);    /* 解の表示 */
			LB->InsertString(-1,outstr);
            for (i=2;i<=N+1;i++){
				outstr="";
				for (j=2;j<=N+1;j++){
                    cbuf.Format(CString("%4d"),m[i][j]);
					outstr+=cbuf;
				}
				LB->InsertString(-1,outstr);
            }
        }
        else
            for (k=0;k<8;k++)           /* 進む位置を選ぶ */
                backtrack(x+dx[k],y+dy[k]);
        m[x][y]=0;                      /* １つ前に戻る */
        count--;
    }
}

void CDr66ListBoxView::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	LB=(CListBox *)GetDlgItem(IDC_LIST1);	// リストボックスの取得
	int i,j;

    for (i=0;i<=N+3;i++)
        for (j=0;j<=N+3;j++)
            if (2<=i && i<=N+1 && 2<=j && j<=N+1)
                m[i][j]=0;      /* 盤面 */
            else
                m[i][j]=1;      /* 壁 */

    backtrack(2,2);
}
