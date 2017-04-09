// Dr18_3View.cpp : CDr18_3View クラスの実装
//

#include "stdafx.h"
#include "Dr18_3.h"

#include "Dr18_3Doc.h"
#include "Dr18_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr18_3View

IMPLEMENT_DYNCREATE(CDr18_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr18_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr18_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr18_3View コンストラクション/デストラクション

CDr18_3View::CDr18_3View()
	: CFormView(CDr18_3View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr18_3View::~CDr18_3View()
{
}

void CDr18_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr18_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr18_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr18_3View 診断

#ifdef _DEBUG
void CDr18_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr18_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr18_3Doc* CDr18_3View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr18_3Doc)));
	return (CDr18_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr18_3View メッセージ ハンドラ
/*
 * -------------------------------
 *      ポインタをソートする     *
 * -------------------------------
 */

#include "mfcform.h"

#define N 10
void CDr18_3View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct girl {
        char *name;
        int age;
    } *t,*p[N],a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
                    "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char *min;
    int s,i,j;

    for (i=0;i<N;i++)     /* データをポインタで指し示す */
        p[i]=&a[i];

    for (i=0;i<N-1;i++){
        min=p[i]->name;
        s=i;
        for (j=i+1;j<N;j++){
            if (strcmp(p[j]->name,min)<0){
                min=p[j]->name;
                s=j;
            }
        }
        t=p[i]; p[i]=p[s]; p[s]=t;    /* ポインタの交換 */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%10s%4d\n",p[i]->name,p[i]->age);
	tfin();
}
