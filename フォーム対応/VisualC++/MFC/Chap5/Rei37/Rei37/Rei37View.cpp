// Rei37View.cpp : CRei37View クラスの実装
//

#include "stdafx.h"
#include "Rei37.h"

#include "Rei37Doc.h"
#include "Rei37View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei37View

IMPLEMENT_DYNCREATE(CRei37View, CFormView)

BEGIN_MESSAGE_MAP(CRei37View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei37View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei37View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei37View コンストラクション/デストラクション

CRei37View::CRei37View()
	: CFormView(CRei37View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei37View::~CRei37View()
{
}

void CRei37View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CRei37View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei37View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei37View 診断

#ifdef _DEBUG
void CRei37View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei37View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei37Doc* CRei37View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei37Doc)));
	return (CRei37Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei37View メッセージ ハンドラ
/*
 * -----------------------------------
 *      双方向リストデータの作成     *
 * -----------------------------------
 */

#include "mfcform.h"

struct tfield {
    struct tfield *left;    /* 逆ポインタ */
    char name[20];          /* 名前       */
    char tel[20];           /* 電話番号   */
    struct tfield *right;   /* 順ポインタ */
} *head,*tail=NULL;

struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CRei37View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
	p->left=tail;
    tail=p;
}

void CRei37View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	p=tail;                 /* 順リストの作成 */
    head=NULL;
    while (p!=NULL){
        p->right=head;
        head=p;
        p=p->left;
    }

	tinit();cls();
    printf("順方向リスト\n");
    p=head;                 /* リストの順表示 */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->right;
    }

    printf("逆方向リスト\n");
    p=tail;                 /* リストの逆表示 */
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->left;
    }
	tfin();
}
