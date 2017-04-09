// Rei35View.cpp : CRei35View クラスの実装
//

#include "stdafx.h"
#include "Rei35.h"

#include "Rei35Doc.h"
#include "Rei35View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei35View

IMPLEMENT_DYNCREATE(CRei35View, CFormView)

BEGIN_MESSAGE_MAP(CRei35View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei35View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei35View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CRei35View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CRei35View コンストラクション/デストラクション

CRei35View::CRei35View()
	: CFormView(CRei35View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei35View::~CRei35View()
{
}

void CRei35View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CRei35View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei35View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei35View 診断

#ifdef _DEBUG
void CRei35View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei35View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei35Doc* CRei35View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei35Doc)));
	return (CRei35Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei35View メッセージ ハンドラ


/*
 * -------------------------------
 *      リストデータへの追加     *
 * -------------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} *head=NULL;  // 関数の外で宣言
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CRei35View::OnBnClickedButton1()
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
void CRei35View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p,*n;
	char key[20]; 
	n=talloc();
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,n->name);
	text2.GetWindowText(buf);
	stoc(buf,n->tel);
	text3.GetWindowText(buf);
	stoc(buf,key);

    p=head;
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            n->pointer=p->pointer;
            p->pointer=n;
            return;
        }
        p=p->pointer;
    }
	tinit();cls();
    printf("キーデータが見つかりません\n");
	tfin();
}
void CRei35View::OnBnClickedButton3()
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
