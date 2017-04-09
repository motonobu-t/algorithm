// Dr43View.cpp : CDr43View クラスの実装
//

#include "stdafx.h"
#include "Dr43.h"

#include "Dr43Doc.h"
#include "Dr43View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr43View

IMPLEMENT_DYNCREATE(CDr43View, CFormView)

BEGIN_MESSAGE_MAP(CDr43View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr43View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr43View コンストラクション/デストラクション

CDr43View::CDr43View()
	: CFormView(CDr43View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr43View::~CDr43View()
{
}

void CDr43View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr43View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr43View 診断

#ifdef _DEBUG
void CDr43View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr43View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr43Doc* CDr43View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr43Doc)));
	return (CDr43Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr43View メッセージ ハンドラ
/*
 * ---------------------------
 *      最小ノードの探索     *
 * ---------------------------
 */

#include "mfcform.h"
struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char name[12];          /* 名前 */
    struct tnode *right;    /* 右部分木へのポインタ */
} *root;
int flag=0;  // ボタンの最初のクリックを判定
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void CDr43View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tnode *p,*old;
	char dat[12];
	CString buf;

	if (flag==0){
		root=talloc();                  /* ルート・ノード */
		text1.GetWindowText(buf);
		stoc(buf,root->name);
	    root->left=root->right=NULL;
		flag=1;
	}
	else {
		text1.GetWindowText(buf);
		stoc(buf,dat);
        p=root;                     /* 木のサーチ */
        while (p!=NULL){
            old=p;
            if (strcmp(dat,p->name)<=0)
                p=p->left;
            else
                p=p->right;
        }
        p=talloc();                 /* 新しいノードの接続 */
        strcpy(p->name,dat);
        p->left=p->right=NULL;
        if (strcmp(dat,old->name)<=0)
            old->left=p;
        else
            old->right=p;
    }
	tinit();cls();
	p=root;                    /* 最小ノードの探索 */
    while (p->left!=NULL)
        p=p->left;
    printf("最小ノード＝ %s\n",p->name);

    p=root;                    /* 最大ノードの探索 */
    while (p->right!=NULL)
        p=p->right;
    printf("最大ノード＝ %s\n",p->name);
	tfin();
}
