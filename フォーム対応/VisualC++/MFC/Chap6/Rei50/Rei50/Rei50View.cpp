// Rei50View.cpp : CRei50View クラスの実装
//

#include "stdafx.h"
#include "Rei50.h"

#include "Rei50Doc.h"
#include "Rei50View.h"
#include "Input.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei50View

IMPLEMENT_DYNCREATE(CRei50View, CFormView)

BEGIN_MESSAGE_MAP(CRei50View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei50View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei50View コンストラクション/デストラクション

CRei50View::CRei50View()
	: CFormView(CRei50View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei50View::~CRei50View()
{
}

void CRei50View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CRei50View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei50View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei50View 診断

#ifdef _DEBUG
void CRei50View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei50View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei50Doc* CRei50View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei50Doc)));
	return (CRei50Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei50View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      質疑応答と決定木（配列表現）     *
 * ---------------------------------------
 */

#define Max 100
#define nil -1
struct tnode {
    int left;      /* 左へのポインタ */
    CString node;  /* CString型で統一 */
    int right;     /* 右へのポインタ */
};
struct tnode a[Max]={{1  ,CString("芸能人ですか")  ,2},
                     {3  ,CString("歌手ですか")    ,4},
                     {nil,CString("吉田　茂")      ,nil},
                     {nil,CString("井上　陽水")    ,nil},
                     {5  ,CString("女優ですか")    ,6},
                     {nil,CString("中山　美穂")    ,nil},
                     {nil,CString("久米 宏")       ,nil}};
int lp=6;
void CRei50View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	CInput dlg;  // 入力用ダイアログボックス
	int p,c;
	do {
        p=0;
        while (a[p].left!=nil){          /* 木のサーチ */
			c=AfxMessageBox(CString(a[p].node),MB_YESNO);
            if (c==IDYES)
                p=a[p].left;
            else
                p=a[p].right;
        }
		c=AfxMessageBox(CString(a[p].node),MB_YESNO);

        if (c==IDNO){               /* 学習機能 */
            a[lp+1]=a[p];                    /* ノードの移動 */
                                           /* 新しいノードの作成 */
			dlg.m_msg="あなたの考えは";
			dlg.m_text="";
			dlg.DoModal();
			a[lp+2].node=dlg.m_text;
            a[lp+2].left=a[lp+2].right=nil;
                                            /* 質問ノードの作成 */
			dlg.m_msg=a[lp+1].node+CString("と")+a[lp+2].node+CString("を区別する質問は");
			dlg.m_text="";
			dlg.DoModal();
			a[p].node=dlg.m_text;
			c=AfxMessageBox(CString("ｙｅｓの項目は")+a[lp+1].node+CString("で良いですか"),MB_YESNO);
            if (c==IDYES){          /* 子の接続 */
                a[p].left=lp+1; a[p].right=lp+2;
            }
            else {
                a[p].left=lp+2; a[p].right=lp+1;
            }
            lp=lp+2;
        }
    } while (c=AfxMessageBox(CString("続けますか"),MB_YESNO),c==IDYES);
}
