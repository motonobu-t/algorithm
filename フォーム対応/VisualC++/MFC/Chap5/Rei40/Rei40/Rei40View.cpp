// Rei40View.cpp : CRei40View クラスの実装
//

#include "stdafx.h"
#include "Rei40.h"

#include "Rei40Doc.h"
#include "Rei40View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei40View

IMPLEMENT_DYNCREATE(CRei40View, CFormView)

BEGIN_MESSAGE_MAP(CRei40View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei40View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei40View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei40View コンストラクション/デストラクション

CRei40View::CRei40View()
	: CFormView(CRei40View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei40View::~CRei40View()
{
}

void CRei40View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_EDIT3, text3);
}

BOOL CRei40View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei40View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei40View 診断

#ifdef _DEBUG
void CRei40View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei40View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei40Doc* CRei40View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei40Doc)));
	return (CRei40Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei40View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      自己再編成探索（先頭に移す）     *
 * ---------------------------------------
 */

#include "mfcform.h"

struct tfield {
    char name[20];             /* 名前 */
    char tel[20];              /* 電話番号 */
    struct tfield *pointer;    /* 次のデータへのポインタ */
} *head=NULL;
struct tfield *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tfield *)malloc(sizeof(struct tfield));
}

void CRei40View::OnBnClickedButton1()
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

void CRei40View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tfield *p,*old;
	char key[32];
	CString buf;
	text3.GetWindowText(buf);
	stoc(buf,key);
    p=old=head;
	tinit();cls();
    while (p!=NULL){
        if (strcmp(key,p->name)==0){
            printf("%15s%15s\n",p->name,p->tel);
            if (p!=head){
                old->pointer=p->pointer;    /* 先頭に移す */
                p->pointer=head;
                head=p;
            }
            break;
        }
        old=p;
        p=p->pointer;
    }
	tfin();
}
