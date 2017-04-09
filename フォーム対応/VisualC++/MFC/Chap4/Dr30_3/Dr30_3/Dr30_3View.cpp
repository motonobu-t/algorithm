// Dr30_3View.cpp : CDr30_3View クラスの実装
//

#include "stdafx.h"
#include "Dr30_3.h"

#include "Dr30_3Doc.h"
#include "Dr30_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_3View

IMPLEMENT_DYNCREATE(CDr30_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr30_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr30_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr30_3View コンストラクション/デストラクション

CDr30_3View::CDr30_3View()
	: CFormView(CDr30_3View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr30_3View::~CDr30_3View()
{
}

void CDr30_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr30_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr30_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr30_3View 診断

#ifdef _DEBUG
void CDr30_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr30_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr30_3Doc* CDr30_3View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr30_3Doc)));
	return (CDr30_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr30_3View メッセージ ハンドラ
/*
 * -------------------------------------
 *      枠の中を埋める（ペイント）     *
 * -------------------------------------
 */

#include "mfcform.h"

int m[10][10]={{2,2,2,2,2,2,2,2,2,2},
               {2,0,0,0,0,0,0,0,0,2},
               {2,0,0,0,0,0,0,0,0,2},
               {2,0,2,2,2,2,2,2,2,2},
               {2,0,2,0,0,2,0,2,0,2},
               {2,0,2,0,0,2,0,2,0,2},
               {2,0,0,2,2,2,0,2,0,2},
               {2,0,2,2,2,2,0,2,0,2},
               {2,0,0,0,0,0,0,0,0,2},
               {2,2,2,2,2,2,2,2,2,2}};
void visit(int i,int j)
{
    m[i][j]=1;
    if (m[i][j+1]==0) visit(i,j+1);
    if (m[i+1][j]==0) visit(i+1,j);
    if (m[i][j-1]==0) visit(i,j-1);
    if (m[i-1][j]==0) visit(i-1,j);
}
void CDr30_3View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j;

    visit(1,1);
	tinit();cls();
    for (i=0;i<10;i++){
        for (j=0;j<10;j++)
            printf("%2d",m[i][j]);
        printf("\n");
    }
	tfin();
}
