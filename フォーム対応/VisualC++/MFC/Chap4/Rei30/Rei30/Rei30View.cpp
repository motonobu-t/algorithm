// Rei30View.cpp : CRei30View クラスの実装
//

#include "stdafx.h"
#include "Rei30.h"

#include "Rei30Doc.h"
#include "Rei30View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei30View

IMPLEMENT_DYNCREATE(CRei30View, CFormView)

BEGIN_MESSAGE_MAP(CRei30View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei30View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei30View コンストラクション/デストラクション

CRei30View::CRei30View()
	: CFormView(CRei30View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei30View::~CRei30View()
{
}

void CRei30View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei30View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei30View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei30View 診断

#ifdef _DEBUG
void CRei30View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei30View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei30Doc* CRei30View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei30Doc)));
	return (CRei30Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei30View メッセージ ハンドラ
/*
 * -------------------------------------------
 *      迷路をたどる（１つだけ見つける）     *
 * -------------------------------------------
 */

#include "mfcform.h"

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success;
int visit(int i,int j)
{
    m[i][j]=1;                /* 訪れた位置に印をつける */

    if (i==Ei && j==Ej)       /* 出口に到達したとき */
        success=1;
                               /* 出口に到達しない間迷路をさまよう */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    if (success==1)          /* 通過点の表示 */
        printf("(%d,%d) ",i,j);
    return success;
}

void CRei30View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    success=0;                  /* 脱出に成功したかを示すフラグ */
    Si=1; Sj=1; Ei=5; Ej=5;     /* 入口と出口の位置 */
	tinit();cls();
    printf("\n迷路の探索\n");
    if (visit(Si,Sj)==0)
        printf("出口は見つかりませんでした\n");
    printf("\n");
	tfin();
}
