// Dr34_2View.cpp : CDr34_2View クラスの実装
//

#include "stdafx.h"
#include "Dr34_2.h"

#include "Dr34_2Doc.h"
#include "Dr34_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr34_2View

IMPLEMENT_DYNCREATE(CDr34_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr34_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr34_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr34_2View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr34_2View::OnBnClickedButton3)
//	ON_WM_ACTIVATE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDr34_2View コンストラクション/デストラクション

CDr34_2View::CDr34_2View()
	: CFormView(CDr34_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr34_2View::~CDr34_2View()
{
}

void CDr34_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CDr34_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr34_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr34_2View 診断

#ifdef _DEBUG
void CDr34_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr34_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr34_2Doc* CDr34_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr34_2Doc)));
	return (CDr34_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr34_2View メッセージ ハンドラ
/*
 * -----------------------------------------------
 *      リストデータの作成（ダミー・ノード）     *
 * -----------------------------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} *head,*old;    // 関数の外で宣言
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CDr34_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	CString buf;
	p=talloc();
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
	old->pointer=p;
    old=p;
}

void CDr34_2View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    old->pointer=NULL;
}

void CDr34_2View::OnBnClickedButton3()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	tinit();cls();
	p=head->pointer;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	tfin();
}

int CDr34_2View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ここに特定な作成コードを追加してください。
	head=talloc();      /* ダミー・ノードの作成 */
	old=head;

	return 0;
}
