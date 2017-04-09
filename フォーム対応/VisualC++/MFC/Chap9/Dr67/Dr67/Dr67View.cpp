// Dr67View.cpp : CDr67View クラスの実装
//

#include "stdafx.h"
#include "Dr67.h"

#include "Dr67Doc.h"
#include "Dr67View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr67View

IMPLEMENT_DYNCREATE(CDr67View, CFormView)

BEGIN_MESSAGE_MAP(CDr67View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr67View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr67View コンストラクション/デストラクション

CDr67View::CDr67View()
	: CFormView(CDr67View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr67View::~CDr67View()
{
}

void CDr67View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr67View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr67View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr67View 診断

#ifdef _DEBUG
void CDr67View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr67View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr67Doc* CDr67View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr67Doc)));
	return (CDr67Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr67View メッセージ ハンドラ
/*
 * --------------------------------------------------------
 *   ダイナミック・プグラミング（釣銭の枚数を最小にする） *
 * --------------------------------------------------------
 */

#include "mfcform.h"

#define limit 42    /* 釣銭金額 */
#define n 3         /* コインの種類 */

void CDr67View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int size[]={1,10,25};
    int value[limit+1],     /* 枚数 */
        item[limit+1],      /* コインの番号 */
        i,s,p,newvalue;

    for (s=0;s<=limit;s++){
        value[s]=s;          /* 初期値 */
    }
    for (i=0;i<n;i++){                    /* コインの番号 */
        for (s=size[i];s<=limit;s++){     /* ナップのサイズ */
            p=s-size[i];
            newvalue=value[p]+1;
            if (newvalue<=value[s]){
                value[s]=newvalue;item[s]=i;     /* 最適解の更新 */
            }
        }
    }
	tinit();cls();
    printf("コインの枚数 =%3d : ",value[limit]);
    for (s=limit;s>0;s=s-size[item[s]])
        printf("%3d,",size[item[s]]);
    printf("\n");
	tfin();
}
