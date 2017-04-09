// Rei33View.cpp : CRei33View クラスの実装
//

#include "stdafx.h"
#include "Rei33.h"

#include "Rei33Doc.h"
#include "Rei33View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei33View

IMPLEMENT_DYNCREATE(CRei33View, CFormView)

BEGIN_MESSAGE_MAP(CRei33View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei33View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei33View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei33View コンストラクション/デストラクション

CRei33View::CRei33View()
	: CFormView(CRei33View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei33View::~CRei33View()
{
}

void CRei33View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei33View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei33View 診断

#ifdef _DEBUG
void CRei33View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei33View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei33Doc* CRei33View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei33Doc)));
	return (CRei33Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei33View メッセージ ハンドラ
/*
 * -----------------------------
 *      キュー（待ち行列）     *
 * -----------------------------
 */

#include "mfcform.h"

#define MaxSize 100     /* キュー・サイズ */
int queue[MaxSize];     /* キュー */
int head=0,             /* 先頭データへのポインタ */
    tail=0;             /* 終端データへのポインタ */
int queuein(int n)       /* キューにデータを入れる手続き */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;       /* キューが一杯のとき */
}
int queueout(int *n)     /* キューからデータを取り出す手続き */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;       /* キューが空のとき */
}

void CRei33View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
	if (queuein(n)==-1){
        printf("待ち行列が一杯です\n");
    }
	tfin();
}

void CRei33View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	tinit();cls();
    if (queueout(&n)==-1)
        printf("待ち行列は空です\n");
    else
        printf("queue data --> %d\n",n);
	tfin();
}
