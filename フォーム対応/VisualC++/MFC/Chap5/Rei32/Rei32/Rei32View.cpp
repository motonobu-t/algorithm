// Rei32View.cpp : CRei32View クラスの実装
//

#include "stdafx.h"
#include "Rei32.h"

#include "Rei32Doc.h"
#include "Rei32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei32View

IMPLEMENT_DYNCREATE(CRei32View, CFormView)

BEGIN_MESSAGE_MAP(CRei32View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei32View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei32View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei32View コンストラクション/デストラクション

CRei32View::CRei32View()
	: CFormView(CRei32View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei32View::~CRei32View()
{
}

void CRei32View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei32View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei32View 診断

#ifdef _DEBUG
void CRei32View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei32View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei32Doc* CRei32View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei32Doc)));
	return (CRei32Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei32View メッセージ ハンドラ
/*
 * -------------------
 *      スタック     *
 * -------------------
 */

#include "mfcform.h"

#define MaxSize 100     /* スタック・サイズ */
int stack[MaxSize];     /* スタック */
int sp=0;               /* スタック・ポインタ */
int push(int n)        /* スタックにデータを積む手続き */
{
    if (sp<MaxSize){
        stack[sp]=n;
        sp++;
        return 0;
    }
    else
        return -1;     /* スタックが一杯のとき */
}
int pop(int *n)        /* スタックからデータを取り出す手続き */
{
    if (sp>0){
        sp--;
        *n=stack[sp];
        return 0;
    }
    else
        return -1;     /* スタックが空のとき */
}

void CRei32View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
	if (push(n)==-1){
       printf("スタックが一杯です\n");
    }
	tfin();
}

void CRei32View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	tinit();cls();
	if (pop(&n)==-1)
        printf("スタックは空です\n");
    else
        printf("stack data --> %d\n",n);
	tfin();
}
