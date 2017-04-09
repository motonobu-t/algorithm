// Rei42View.cpp : CRei42View クラスの実装
//

#include "stdafx.h"
#include "Rei42.h"

#include "Rei42Doc.h"
#include "Rei42View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei42View

IMPLEMENT_DYNCREATE(CRei42View, CFormView)

BEGIN_MESSAGE_MAP(CRei42View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei42View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei42View コンストラクション/デストラクション

CRei42View::CRei42View()
	: CFormView(CRei42View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei42View::~CRei42View()
{
}

void CRei42View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei42View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei42View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei42View 診断

#ifdef _DEBUG
void CRei42View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei42View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei42Doc* CRei42View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei42Doc)));
	return (CRei42Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei42View メッセージ ハンドラ
/*
 * -------------------------------
 *      ２分探索木の配列表現     *
 * -------------------------------
 */

#include "mfcform.h"

#define nil -1
#define MaxSize 100

struct tnode {
    int left;           /* 左部分木へのポインタ */
    char name[12];
    int right;          /* 右部分木へのポインタ */
};

void CRei42View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct tnode a[MaxSize]={{  1,"Machilda",  2},{  3,"Candy",  4},
                             {  5,"Rolla"   ,nil},{nil,"Ann"  ,nil},
                             {  6,"Emy"     ,  7},{nil,"Nancy",nil},
                             {nil,"Eluza"   ,nil},{nil,"Lisa" ,nil}};
    char key[12];
    int p;

	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
	tinit();cls();
    p=0;
    while (p!=nil){
        if (strcmp(key,a[p].name)==0){
            printf("見つかりました\n");
            break;
        }
        else if (strcmp(key,a[p].name)<0)
            p=a[p].left;                    /* 左部分木へ移動 */
        else
            p=a[p].right;                   /* 右部分木へ移動 */
    }
	tfin();
}
