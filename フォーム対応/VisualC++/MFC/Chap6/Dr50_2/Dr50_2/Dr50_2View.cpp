// Dr50_2View.cpp : CDr50_2View クラスの実装
//

#include "stdafx.h"
#include "Dr50_2.h"

#include "Dr50_2Doc.h"
#include "Dr50_2View.h"
#include "Input.h"
#include <wchar.h>
#include <locale.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr50_2View

IMPLEMENT_DYNCREATE(CDr50_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr50_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr50_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr50_2View コンストラクション/デストラクション

CDr50_2View::CDr50_2View()
	: CFormView(CDr50_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr50_2View::~CDr50_2View()
{
}

void CDr50_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr50_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr50_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr50_2View 診断

#ifdef _DEBUG
void CDr50_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr50_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr50_2Doc* CDr50_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr50_2Doc)));
	return (CDr50_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr50_2View メッセージ ハンドラ
/*
 * -------------------------------------------
 *      木（動的表現）のディスクへの保存     *
 * -------------------------------------------
 */

struct tnode {
    struct tnode *left;  /* 左へのポインタ */
    wchar_t node[30];      /* 動的メモリ割り当てを行うため固定長配列 */
    struct tnode *right; /* 右へのポインタ */
};
struct tnode *root;
#define Rec 34L         /* レコード・サイズ */
#define Leaf -1         /* 葉 */
FILE *fp;

struct tnode *talloc(void)            /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *readtree(struct tnode *p)    /* ファイルから木をリード */
{
    int flag;
    p=talloc();
    fwscanf(fp,L"%30ls%4d",p->node,&flag);
    if (flag==Leaf)
        p->left=p->right=NULL;
    else{
        p->left=readtree(p->left);
        p->right=readtree(p->right);
    }
    return p;
}
void writetree(struct tnode *p)      /* ファイルに木をライト */
{
    if (p!=NULL){
        if (p->left==NULL)
            fwprintf(fp,L"%30ls%4d",p->node,Leaf);
        else
            fwprintf(fp,L"%30ls%4d",p->node,!Leaf);
        writetree(p->left);
        writetree(p->right);
    }
}
void CDr50_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tnode *p,*q1,*q2;
    int c;
	CInput dlg;  // 入力用ダイアログボックス

	setlocale(LC_ALL,"");
	if ((fp=fopen("dbase.dat","r"))==NULL){
        root=talloc();
		dlg.m_msg="初期ノード ? ";
		dlg.m_text="";
		dlg.DoModal();
		_tcscpy_s(root->node,dlg.m_text);
		root->left=root->right=NULL;
    }
    else {
        root=readtree(root);
        fclose(fp);
    }
	do {
        p=root;                             /* 木のサーチ */
        while (p->left!=NULL){
			c=AfxMessageBox(CString(p->node),MB_YESNO);
            if (c==IDYES)
                p=p->left;
            else
                p=p->right;
        }
		c=AfxMessageBox(CString("答えは")+CString(p->node)+CString("です"),MB_YESNO);

        if (c==IDNO){                         /* 学習機能 */
            q1=talloc(); *q1=*p;        /* ノードの移動 */

            q2=talloc();                /* 新しいノードの作成 */
			dlg.m_msg="あなたの考えは";
			dlg.m_text="";
			dlg.DoModal();
			_tcscpy_s(q2->node,dlg.m_text);
            q2->left=q2->right=NULL;
                                        /* 質問ノードの作成 */
			dlg.m_msg=q1->node+CString("と")+q2->node+CString("を区別する質問は");
			dlg.m_text="";
			dlg.DoModal();
			_tcscpy_s(p->node,dlg.m_text);
			c=AfxMessageBox(CString("ｙｅｓの項目は")+q1->node+CString("で良いですか"),MB_YESNO);


            if (c==IDYES){      /* 子の接続 */
                p->left=q1; p->right=q2;
            }
            else {
                p->left=q2; p->right=q1;
            }
        }
    } while (c=AfxMessageBox(CString("続けますか"),MB_YESNO),c==IDYES);
    if ((fp=fopen("dbase.dat","w"))!=NULL){
        writetree(root);
        fclose(fp);
    }
}
