// Dr42View.cpp : CDr42View クラスの実装
//

#include "stdafx.h"
#include "Dr42.h"

#include "Dr42Doc.h"
#include "Dr42View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr42View

IMPLEMENT_DYNCREATE(CDr42View, CFormView)

BEGIN_MESSAGE_MAP(CDr42View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr42View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr42View コンストラクション/デストラクション

CDr42View::CDr42View()
	: CFormView(CDr42View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr42View::~CDr42View()
{
}

void CDr42View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr42View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr42View 診断

#ifdef _DEBUG
void CDr42View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr42View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr42Doc* CDr42View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr42Doc)));
	return (CDr42Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr42View メッセージ ハンドラ
/*
 * -----------------------------------
 *      ２分探索木へのデータ追加     *
 * -----------------------------------
 */

#include "mfcform.h"

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* 左部分木へのポインタ */
    char name[12];
    int right;          /* 右部分木へのポインタ */
};

int sp=8;               /* ノードの格納現在位置 */
struct tnode a[MaxSize]={{  1,"Machilda",  2},
                         {  3,"Candy",  4},
                         {  5,"Rolla"   ,nil},
                         {nil,"Ann"  ,nil},
                         {  6,"Emy"     ,  7},
                         {nil,"Nancy",nil},
                         {nil,"Eluza"   ,nil},
                         {nil,"Lisa" ,nil}};

void CDr42View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char key[12];
    int p,old,i;

	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
    p=0;                                /* 木のサーチ */
    while (p!=nil){
        old=p;
        if (strcmp(key,a[p].name)<=0)
            p=a[p].left;
        else
            p=a[p].right;
    }

    a[sp].left=a[sp].right=nil;         /* 新しいノードの接続 */
    strcpy(a[sp].name,key);
    if (strcmp(key,a[old].name)<=0)
        a[old].left=sp;
    else
        a[old].right=sp;
    sp++;

	tinit();cls();
    for (i=0;i<sp;i++)                  /* ノード・テーブルの表示 */
        printf("%4d%12s%4d\n",a[i].left,a[i].name,a[i].right);
	tfin();
}
