// Rei47View.cpp : CRei47View クラスの実装
//

#include "stdafx.h"
#include "Rei47.h"

#include "Rei47Doc.h"
#include "Rei47View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei47View

IMPLEMENT_DYNCREATE(CRei47View, CFormView)

BEGIN_MESSAGE_MAP(CRei47View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei47View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei47View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei47View コンストラクション/デストラクション

CRei47View::CRei47View()
	: CFormView(CRei47View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei47View::~CRei47View()
{
}

void CRei47View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei47View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei47View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei47View 診断

#ifdef _DEBUG
void CRei47View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei47View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei47Doc* CRei47View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei47Doc)));
	return (CRei47Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei47View メッセージ ハンドラ
/*
 * -----------------------
 *      ヒープの作成     *
 * -----------------------
 */

#include "mfcform.h"
int heap[100],n=1;
void CRei47View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int s,p,w;
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
    s=n;
    p=s/2;          /* 親の位置 */
    while (s>=2 && heap[p]>heap[s]){    /* 上方移動 */
        w=heap[p];heap[p]=heap[s];heap[s]=w;
        s=p;p=s/2;
    }
    n++;
}

void CRei47View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int i;
	tinit();cls();
	for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	tfin();
}
