// Rei8View.cpp : CRei8View クラスの実装
//

#include "stdafx.h"
#include "Rei8.h"

#include "Rei8Doc.h"
#include "Rei8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei8View

IMPLEMENT_DYNCREATE(CRei8View, CFormView)

BEGIN_MESSAGE_MAP(CRei8View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei8View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei8View コンストラクション/デストラクション

CRei8View::CRei8View()
	: CFormView(CRei8View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei8View::~CRei8View()
{
}

void CRei8View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei8View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei8View 診断

#ifdef _DEBUG
void CRei8View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei8View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei8Doc* CRei8View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei8Doc)));
	return (CRei8Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei8View メッセージ ハンドラ
/*
 * --------------------------------
 *     一様乱数（線形合同法）     *
 * --------------------------------
 */

#include "mfcform.h"

unsigned rndnum=13;        /* 乱数の初期値 */
unsigned irnd(void)        /* 0～32767の整数乱数 */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}

void CRei8View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int j;
	tinit();cls();
    for (j=0;j<100;j++){
        printf("%8d",irnd());
    }
	tfin();
}
