// Dr23View.cpp : CDr23View クラスの実装
//

#include "stdafx.h"
#include "Dr23.h"

#include "Dr23Doc.h"
#include "Dr23View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr23View

IMPLEMENT_DYNCREATE(CDr23View, CFormView)

BEGIN_MESSAGE_MAP(CDr23View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr23View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr23View コンストラクション/デストラクション

CDr23View::CDr23View()
	: CFormView(CDr23View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr23View::~CDr23View()
{
}

void CDr23View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr23View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr23View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr23View 診断

#ifdef _DEBUG
void CDr23View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr23View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr23Doc* CDr23View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr23Doc)));
	return (CDr23Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr23View メッセージ ハンドラ
/*
 * ---------------------------------------------------
 *      文字列の照合（Ｂｏｙｅｒ－Ｍｏｏｒｅ法）     *
 * ---------------------------------------------------
 */

#include "mfcform.h"

int skip[256];
void table(char *key)      /* スキップ・テーブルの作成 */
{
    int k,n;

    n=strlen(key);
    for (k=0;k<=255;k++)
        skip[k]=n;
    for (k=0;k<n-1;k++)
        skip[key[k]]=n-1-k;
}
char *search(char *text,char *key)
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);

    p=text+n-1;
    while (p<text+m){
        if (*p==key[n-1]){                   /* 右端の文字だけ比較 */
            if (strncmp(p-n+1,key,n)==0)     /* キー全体を比較     */
                return p-n+1;
        }
        p=p+skip[*p];                        /* サーチ位置を進める */
    }
    return NULL;
}

void CDr23View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    static char text[]="This is a pen. That is a pencil.";
    char *p,*key="pen";
	tinit();cls();
    table(key);
    p=search(text,key);
    while (p!=NULL){
        printf("%s\n",p);
        p=search(p+strlen(key),key);
    }
	tfin();
}
