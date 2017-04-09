// Dr33View.cpp : CDr33View クラスの実装
//

#include "stdafx.h"
#include "Dr33.h"

#include "Dr33Doc.h"
#include "Dr33View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr33View

IMPLEMENT_DYNCREATE(CDr33View, CFormView)

BEGIN_MESSAGE_MAP(CDr33View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr33View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr33View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr33View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr33View コンストラクション/デストラクション

CDr33View::CDr33View()
	: CFormView(CDr33View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr33View::~CDr33View()
{
}

void CDr33View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr33View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr33View 診断

#ifdef _DEBUG
void CDr33View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr33View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr33Doc* CDr33View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr33Doc)));
	return (CDr33Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr33View メッセージ ハンドラ
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
int queuein(int n)     /* キューにデータを入れる手続き */
{
    if ((tail+1)%MaxSize !=head){
        queue[tail]=n;
        tail++;
        tail=tail%MaxSize;
        return 0;
    }
    else
        return -1;      /* キューが一杯のとき */
}
int queueout(int *n)    /* キューからデータを取り出す手続き */
{
    if (tail!=head){
        *n=queue[head];
        head++;
        head=head%MaxSize;
        return 0;
    }
    else
        return -1;     /* キューが空のとき */
}
void disp(void)        /* 待ち行列の内容を表示する手続き */
{
    int i;

    i=head;
    while (i!=tail){
        printf("%d\n",queue[i]);
        i++;
        i=i%MaxSize;
    }
}
void CDr33View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	CString buf;
	text1.GetWindowText(buf);
	n=stoi(buf);
	tinit();cls();
	if (queuein(n)==-1)
         printf("待ち行列が一杯です\n");
	tfin();
}

void CDr33View::OnBnClickedButton2()
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

void CDr33View::OnBnClickedButton3()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	disp();
	tfin();
}
