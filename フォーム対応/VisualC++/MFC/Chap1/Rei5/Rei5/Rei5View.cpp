// Rei5View.cpp : CRei5View クラスの実装
//

#include "stdafx.h"
#include "Rei5.h"

#include "Rei5Doc.h"
#include "Rei5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei5View

IMPLEMENT_DYNCREATE(CRei5View, CFormView)

BEGIN_MESSAGE_MAP(CRei5View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei5View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CRei5View::OnStnClickedPict)
END_MESSAGE_MAP()

// CRei5View コンストラクション/デストラクション

CRei5View::CRei5View()
	: CFormView(CRei5View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei5View::~CRei5View()
{
}

void CRei5View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei5View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei5View 診断

#ifdef _DEBUG
void CRei5View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei5View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei5Doc* CRei5View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei5Doc)));
	return (CRei5Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei5View メッセージ ハンドラ
/*
 * ------------------------------------
 *     モンテカルロ法によるπの計算   *
 * ------------------------------------
 */

#include "mfcform.h"

#define NUM 1000
double rnd(void)        /* ０～１の乱数 */
{
    return (double)rand()/(RAND_MAX+0.1);
}

void CRei5View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double x,y,pai;
    int i,in=0;

    for (i=1;i<=NUM;i++){
        x=rnd();
        y=rnd();
        if (x*x+y*y<=1)
            in++;
    }
    pai=(double)4*in/NUM;

	tinit();cls();
    printf("πの値=%f\n",pai);
	tfin();
}

//void CRei5View::OnStnClickedPict()
//{
//	// TODO: ここにコントロール通知ハンドラ コードを追加します。
//}
