// Dr34_1View.cpp : CDr34_1View クラスの実装
//

#include "stdafx.h"
#include "Dr34_1.h"

#include "Dr34_1Doc.h"
#include "Dr34_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr34_1View

IMPLEMENT_DYNCREATE(CDr34_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr34_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr34_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr34_1View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDr34_1View::OnBnClickedButton3)
END_MESSAGE_MAP()

// CDr34_1View コンストラクション/デストラクション

CDr34_1View::CDr34_1View()
	: CFormView(CDr34_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr34_1View::~CDr34_1View()
{
}

void CDr34_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
}

BOOL CDr34_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr34_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr34_1View 診断

#ifdef _DEBUG
void CDr34_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr34_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr34_1Doc* CDr34_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr34_1Doc)));
	return (CDr34_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr34_1View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      リストデータの作成（入力順）     *
 * ---------------------------------------
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

 
int flag=0;  // 登録ボタンが第１回目に押されたかの判定フラグ

void CDr34_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p; 
	CString buf;
	if (flag==0){
	    head=talloc();
		text1.GetWindowText(buf);
		stoc(buf,head->name);
		text2.GetWindowText(buf);
		stoc(buf,head->tel);
		old=head;
		flag=1;
	}
	else {
		p=talloc();
		text1.GetWindowText(buf);
		stoc(buf,p->name);
		text2.GetWindowText(buf);
		stoc(buf,p->tel);
        old->pointer=p;
        old=p;
    }
}

void CDr34_1View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    old->pointer=NULL;
	flag=0;
}

void CDr34_1View::OnBnClickedButton3()
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
