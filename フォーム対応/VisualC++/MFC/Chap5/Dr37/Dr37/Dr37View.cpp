// Dr37View.cpp : CDr37View クラスの実装
//

#include "stdafx.h"
#include "Dr37.h"

#include "Dr37Doc.h"
#include "Dr37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr37View

IMPLEMENT_DYNCREATE(CDr37View, CFormView)

BEGIN_MESSAGE_MAP(CDr37View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr37View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr37View::OnBnClickedButton2)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CDr37View コンストラクション/デストラクション

CDr37View::CDr37View()
	: CFormView(CDr37View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr37View::~CDr37View()
{
}

void CDr37View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr37View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr37View 診断

#ifdef _DEBUG
void CDr37View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr37View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr37Doc* CDr37View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr37Doc)));
	return (CDr37Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr37View メッセージ ハンドラ
/*
 * -----------------------------------------
 *      循環・双方向リストデータの作成     *
 * -----------------------------------------
 */

#include "mfcform.h"

struct tfield {
    struct tfield *left;    /* 逆ポインタ */
    char name[20];          /* 名前       */
    char tel[20];           /* 電話番号   */
    struct tfield *right;   /* 順ポインタ */
} *head;  // 関数の外で宣言
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CDr37View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
    p->right=head;
    p->left=head->left;
    head->left->right=p;
    head->left=p;
}

void CDr37View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	tinit();cls();
	printf("順方向リスト\n");
    p=head->right;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }
    printf("逆方向リスト\n");
    p=head->left;
    while (p!=head){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	tfin();
}

int CDr37View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ここに特定な作成コードを追加してください。
	head=talloc();                  /* ダミー・ノードの作成 */
	head->left=head->right=head;

	return 0;
}
