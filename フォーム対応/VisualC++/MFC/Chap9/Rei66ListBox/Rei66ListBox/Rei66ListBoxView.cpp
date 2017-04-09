// Rei66ListBoxView.cpp : CRei66ListBoxView クラスの実装
//

#include "stdafx.h"
#include "Rei66ListBox.h"

#include "Rei66ListBoxDoc.h"
#include "Rei66ListBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66ListBoxView

IMPLEMENT_DYNCREATE(CRei66ListBoxView, CFormView)

BEGIN_MESSAGE_MAP(CRei66ListBoxView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei66ListBoxView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei66ListBoxView コンストラクション/デストラクション

CRei66ListBoxView::CRei66ListBoxView()
	: CFormView(CRei66ListBoxView::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei66ListBoxView::~CRei66ListBoxView()
{
}

void CRei66ListBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
}

BOOL CRei66ListBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei66ListBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei66ListBoxView 診断

#ifdef _DEBUG
void CRei66ListBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei66ListBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei66ListBoxDoc* CRei66ListBoxView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei66ListBoxDoc)));
	return (CRei66ListBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// CRei66ListBoxView メッセージ ハンドラ
/*
 * -----------------------------------------
 *      八王妃（８Ｑｕｅｅｎｓ）の問題     *
 * -----------------------------------------
 */

#define N 8
int column[N+1],    /* 同じ欄に王妃が置かれているかを表す*/
    rup[2*N+1],     /* 右上がりの対角線上に置かれているかを表す */
    lup[2*N+1],     /* 左上がりの対角線上に置かれているかを表す */
    queen[N+1];     /* 王妃の位置 */

CListBox *LB;		// リストボックス
CString cbuf,		//	書式変換用			
        outstr;		//　１行出力用

void backtrack(int i)
{
    int j,x,y;
    static int num=0;

    if (i>N){
		outstr.Format(CString("解%3d"),++num);    /* 解の表示 */
		LB->InsertString(-1,outstr);  // AddStringではうまくいかない
		for (y=1;y<=N;y++){
			outstr="";
			for (x=1;x<=N;x++){
				if (queen[y]==x){
					outstr+=" Q";
				}
				else{
					outstr+=" .";
				}
			}
			LB->InsertString(-1,outstr); // AddStringではうまくいかない
		}
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

void CRei66ListBoxView::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	LB=(CListBox *)GetDlgItem(IDC_LIST1);	// リストボックスの取得
	int i;

    for (i=1;i<=N;i++)
        column[i]=1;
    for (i=1;i<=2*N;i++)
        rup[i]=lup[i]=1;
    backtrack(1);
}
