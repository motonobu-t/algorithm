// Dr35_1View.cpp : CDr35_1View クラスの実装
//

#include "stdafx.h"
#include "Dr35_1.h"

#include "Dr35_1Doc.h"
#include "Dr35_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr35_1View

IMPLEMENT_DYNCREATE(CDr35_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr35_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr35_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr35_1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr35_1View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr35_1View コンストラクション/デストラクション

CDr35_1View::CDr35_1View()
	: CFormView(CDr35_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr35_1View::~CDr35_1View()
{
}

void CDr35_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CDr35_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr35_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr35_1View 診断

#ifdef _DEBUG
void CDr35_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr35_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr35_1Doc* CDr35_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr35_1Doc)));
	return (CDr35_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr35_1View メッセージ ハンドラ
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
} *head=NULL;  // 初期化する
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}
void CDr35_1View::OnBnClickedButton1()
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

void CDr35_1View::OnBnClickedButton2()
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
    printf("%s が見つからないので先頭に追加します\n",key);
	tfin();
	n->pointer=head;
    head=n;
}

void CDr35_1View::OnBnClickedButton3()
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
