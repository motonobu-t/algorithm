// Dr22View.cpp : CDr22View クラスの実装
//

#include "stdafx.h"
#include "Dr22.h"

#include "Dr22Doc.h"
#include "Dr22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr22View

IMPLEMENT_DYNCREATE(CDr22View, CFormView)

BEGIN_MESSAGE_MAP(CDr22View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr22View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr22View コンストラクション/デストラクション

CDr22View::CDr22View()
	: CFormView(CDr22View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr22View::~CDr22View()
{
}

void CDr22View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr22View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr22View 診断

#ifdef _DEBUG
void CDr22View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr22View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr22Doc* CDr22View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr22Doc)));
	return (CDr22Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr22View メッセージ ハンドラ
/*
 * --------------------------
 *      マージ （併合）     *
 * --------------------------
 */

#include "mfcform.h"

#define M 13
#define N 5
#define MaxEof 9999        /* 番兵 */
void CDr22View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={2,4,5,7,8,10,15,20,30,40,45,50,60,MaxEof},
        b[]={6,11,25,33,35,MaxEof},
        c[M+N];
    int i,j,p;

    i=j=p=0;
    while (a[i]!=MaxEof || b[j]!=MaxEof){
        if (a[i]<=b[j])
            c[p++]=a[i++];
        else
            c[p++]=b[j++];
    }

	tinit();cls();
    for (i=0;i<M+N;i++)
        printf("%d ",c[i]);
    printf("\n");
	tfin();
}
