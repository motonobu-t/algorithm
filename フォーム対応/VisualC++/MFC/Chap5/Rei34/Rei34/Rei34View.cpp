// Rei34View.cpp : CRei34View クラスの実装
//

#include "stdafx.h"
#include "Rei34.h"

#include "Rei34Doc.h"
#include "Rei34View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei34View

IMPLEMENT_DYNCREATE(CRei34View, CFormView)

BEGIN_MESSAGE_MAP(CRei34View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei34View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei34View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei34View コンストラクション/デストラクション

CRei34View::CRei34View()
	: CFormView(CRei34View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei34View::~CRei34View()
{
}

void CRei34View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CRei34View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei34View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei34View 診断

#ifdef _DEBUG
void CRei34View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei34View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei34Doc* CRei34View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei34Doc)));
	return (CRei34Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei34View メッセージ ハンドラ
/*
 * -----------------------------
 *      リストデータの作成     *
 * -----------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} *head=NULL;  // 関数の外で宣言し初期化
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CRei34View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	p=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,p->name);
	text2.GetWindowText(buf);
	stoc(buf,p->tel);
    p->pointer=head;
    head=p;
}

void CRei34View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p;
	tinit();cls();
	p=head;
    while (p!=NULL){
        printf("%15s%15s\n",p->name,p->tel);
        p=p->pointer;
    }
	tfin();
}
