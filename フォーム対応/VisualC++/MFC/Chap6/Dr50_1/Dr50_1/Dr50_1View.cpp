// Dr50_1View.cpp : CDr50_1View クラスの実装
//

#include "stdafx.h"
#include "Dr50_1.h"

#include "Dr50_1Doc.h"
#include "Dr50_1View.h"
#include "Input.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr50_1View

IMPLEMENT_DYNCREATE(CDr50_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr50_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr50_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr50_1View コンストラクション/デストラクション

CDr50_1View::CDr50_1View()
	: CFormView(CDr50_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr50_1View::~CDr50_1View()
{
}

void CDr50_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CDr50_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr50_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr50_1View 診断

#ifdef _DEBUG
void CDr50_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr50_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr50_1Doc* CDr50_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr50_1Doc)));
	return (CDr50_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr50_1View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      質疑応答と決定木（動的表現）     *
 * ---------------------------------------
 */
struct tnode {
    struct tnode *left;  /* 左へのポインタ */
    wchar_t node[30];      /* 動的メモリ割り当てを行うため固定長配列 */
    struct tnode *right; /* 右へのポインタ */
};
struct tnode *root;

struct tnode *talloc(void)            /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void CDr50_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tnode *p,*q1,*q2;
    int c;
	CInput dlg;  // 入力用ダイアログボックス

    root=talloc();
	dlg.m_msg="初期ノード ? ";
	dlg.m_text="";
	dlg.DoModal();
	_tcscpy_s(root->node,dlg.m_text);  // CString->TCHAR
	root->left=root->right=NULL;
    do {
        p=root;                             /* 木のサーチ */
        while (p->left!=NULL){
			c=AfxMessageBox(CString(p->node),MB_YESNO);
            if (c==IDYES)
                p=p->left;
            else
                p=p->right;
        }
		c=AfxMessageBox(CString("答えは")+CString(p->node)+CString("です。正しいですか y/n"),MB_YESNO);

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
}
