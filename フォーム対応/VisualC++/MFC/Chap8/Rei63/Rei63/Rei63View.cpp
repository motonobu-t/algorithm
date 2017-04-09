// Rei63View.cpp : CRei63View クラスの実装
//

#include "stdafx.h"
#include "Rei63.h"

#include "Rei63Doc.h"
#include "Rei63View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei63View

IMPLEMENT_DYNCREATE(CRei63View, CFormView)

BEGIN_MESSAGE_MAP(CRei63View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei63View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei63View コンストラクション/デストラクション

CRei63View::CRei63View()
	: CFormView(CRei63View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei63View::~CRei63View()
{
}

void CRei63View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei63View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei63View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei63View 診断

#ifdef _DEBUG
void CRei63View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei63View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei63Doc* CRei63View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei63Doc)));
	return (CRei63Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei63View メッセージ ハンドラ
/*
 * -------------------------
 *      樹木曲線その１     *
 * -------------------------
 */

#include "mfcform.h"

double scale,branch;

void tree(int n,double x0,double y0,double leng,double angle)
                                        /* 樹木曲線の再帰手続き */
{
    if (n==0)
        return;

    setpoint(x0,y0); setangle(angle);
    move(leng);

    x0=LPX; y0=LPY;
    tree(n-1,x0,y0,leng/scale,angle-branch);
    tree(n-1,x0,y0,leng/scale,angle+branch);
}

void CRei63View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n;
    double x0,y0,leng,angle;

    n=8;                /* 枝の次数 */
    x0=300.0;y0=50.0;   /* 根の位置 */
    leng=100.0;         /* 枝の長さ */
    angle=90.0;         /* 枝の向き */
    scale=1.4;          /* 枝の伸び率 */
    branch=20.0;        /* 枝の分岐角 */

    ginit(); cls();
    tree(n,x0,y0,leng,angle);
}
