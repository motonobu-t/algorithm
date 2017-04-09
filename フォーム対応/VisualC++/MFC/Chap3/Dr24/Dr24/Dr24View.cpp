// Dr24View.cpp : CDr24View クラスの実装
//

#include "stdafx.h"
#include "Dr24.h"

#include "Dr24Doc.h"
#include "Dr24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr24View

IMPLEMENT_DYNCREATE(CDr24View, CFormView)

BEGIN_MESSAGE_MAP(CDr24View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr24View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr24View コンストラクション/デストラクション

CDr24View::CDr24View()
	: CFormView(CDr24View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr24View::~CDr24View()
{
}

void CDr24View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr24View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr24View 診断

#ifdef _DEBUG
void CDr24View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr24View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr24Doc* CDr24View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr24Doc)));
	return (CDr24Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr24View メッセージ ハンドラ
/*
 * ----------------------------------------
 *     文字列の置き換え（リプレイス）     *
 * ----------------------------------------
 */

#include "mfcform.h"
char *search(char *text,char *key)  // この関数を先に置く
{
    int m,n;
    char *p;

    m=strlen(text);
    n=strlen(key);
    for (p=text;p<=text+m-n;p++){
        if (strncmp(p,key,n)==0)
            return p;
    }
    return NULL;
}
void replace(char *text,char *key,char *rep)
{
    char *p,buf[128];

    p=search(text,key);
    while (p!=NULL){
        *p='\0';
        strcpy_s(buf,128,p+strlen(key));
        strcat_s(text,128,rep);
        strcat_s(text,128,buf);
        p=search(p+strlen(rep),key);
    }
}


void CDr24View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int k;
    static char text[][128]={"     --- サルビアの花 ---",
                             "いつもいつも思ってた",
                             "サルビアの花をあなたの部屋の中に",
                             "投げ入れたくて",
                             "そして君のベッドに",
                             "サルビアの紅い花しきつめて",
                             "僕は君を死ぬまで抱きしめていようと",
                             ""};
	tinit();cls();
    k=0;
    while (text[k][0]!='\0'){
        replace(text[k],"サルビア","か す み 草");
        replace(text[k],"紅","白");
        printf("%s\n",text[k]);
        k++;
    }
	tfin();
}
