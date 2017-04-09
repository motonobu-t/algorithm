// Dr41View.cpp : CDr41View クラスの実装
//

#include "stdafx.h"
#include "Dr41.h"

#include "Dr41Doc.h"
#include "Dr41View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr41View

IMPLEMENT_DYNCREATE(CDr41View, CFormView)

BEGIN_MESSAGE_MAP(CDr41View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr41View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr41View::OnBnClickedButton2)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDr41View コンストラクション/デストラクション

CDr41View::CDr41View()
	: CFormView(CDr41View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr41View::~CDr41View()
{
}

void CDr41View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr41View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr41View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr41View 診断

#ifdef _DEBUG
void CDr41View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr41View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr41Doc* CDr41View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr41Doc)));
	return (CDr41Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr41View メッセージ ハンドラ
/*
 * -----------------------------------------------
 *      リストを用いたハッシュ（終端に追加）     *
 * -----------------------------------------------
 */

#include "mfcform.h"

#define TableSize 1000
#define ModSize   1000

struct tfield {
    char name[12];
    char tel[12];
    struct tfield *pointer;
} *dat[TableSize];             /* ポインタ・テーブル */
int hash(char *s)         /* ハッシュ関数 */
{
    int n;

    n=strlen(s);
    return (s[0]-'A'+(s[n/2-1]-'A')*26+(s[n-2]-'A')*26*26)%ModSize;
}
struct tfield *talloc(void)        /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CDr41View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	struct tfield *p,*q;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);

	n=hash(p->name);
    if (dat[n]==NULL){            /* 空のとき */
        dat[n]=p;
        p->pointer=NULL;
    }
    else {                        /* かちあったとき */
        q=dat[n];
        while (q->pointer!=NULL)  /* 終端へ追加 */
            q=q->pointer;
        q->pointer=p;
        p->pointer=NULL;
    }
}

void CDr41View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int n;
	char key[32];
	struct tfield *p;
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);

	n=hash(key);
    p=dat[n];
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0)
            printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	tfin();
}

int CDr41View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ここに特定な作成コードを追加してください。
	int n;
	for (n=0;n<TableSize;n++)    /* ポインタ・テーブルの初期化 */
        dat[n]=NULL;

	return 0;
}
