// Rei43View.cpp : CRei43View クラスの実装
//

#include "stdafx.h"
#include "Rei43.h"

#include "Rei43Doc.h"
#include "Rei43View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei43View

IMPLEMENT_DYNCREATE(CRei43View, CFormView)

BEGIN_MESSAGE_MAP(CRei43View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei43View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei43View コンストラクション/デストラクション

CRei43View::CRei43View()
	: CFormView(CRei43View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei43View::~CRei43View()
{
}

void CRei43View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei43View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei43View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei43View 診断

#ifdef _DEBUG
void CRei43View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei43View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei43Doc* CRei43View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei43Doc)));
	return (CRei43Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei43View メッセージ ハンドラ
/*
 * ---------------------------
 *      ２分探索木の作成     *
 * ---------------------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char name[12];          /* 名前 */
    struct tnode *right;    /* 右部分木へのポインタ */
} *root;
int flag=0;

struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void CRei43View::OnBnClickedButton1()
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
	printf("左の子\n");
	p=root;
	do {
		printf("%s\n",p->name);
		p=p->left;
	}while (p!=NULL);
	printf("右の子\n");
	p=root;
	do {
		printf("%s\n",p->name);
		p=p->right;
	}while (p!=NULL);
	tfin();
}
