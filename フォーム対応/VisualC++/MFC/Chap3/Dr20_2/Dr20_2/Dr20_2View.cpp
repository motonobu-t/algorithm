// Dr20_2View.cpp : CDr20_2View クラスの実装
//

#include "stdafx.h"
#include "Dr20_2.h"

#include "Dr20_2Doc.h"
#include "Dr20_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_2View

IMPLEMENT_DYNCREATE(CDr20_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr20_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr20_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr20_2View コンストラクション/デストラクション

CDr20_2View::CDr20_2View()
	: CFormView(CDr20_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr20_2View::~CDr20_2View()
{
}

void CDr20_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr20_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr20_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr20_2View 診断

#ifdef _DEBUG
void CDr20_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr20_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr20_2Doc* CDr20_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr20_2Doc)));
	return (CDr20_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr20_2View メッセージ ハンドラ
/*
 * -------------------------------------
 *      逐次探索法（ｂｒｅａｋ版）     *
 * -------------------------------------
 */

#include "mfcform.h"

#define N 10       /* データ数　*/

void CDr20_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct girl {
        char name[12];
        int age;
    } a[]={"Ann",18,"Rolla",19,"Nancy",16,"Eluza",17,"Juliet",18,
           "Machilda",20,"Emy",15,"Candy",16,"Ema",17,"Mari",18};
    char key[20];
    int i,flag=0;
	tinit();cls();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
    for (i=0;i<N;i++){
        if (strcmp(key,a[i].name)==0){
            printf("%s %d\n",a[i].name,a[i].age);
            flag=1;
            break;
        }
    }
    if (flag!=1)
        printf("見つかりませんでした\n");
	tfin();
}
