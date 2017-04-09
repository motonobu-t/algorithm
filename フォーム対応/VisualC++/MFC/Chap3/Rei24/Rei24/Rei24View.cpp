// Rei24View.cpp : CRei24View クラスの実装
//

#include "stdafx.h"
#include "Rei24.h"

#include "Rei24Doc.h"
#include "Rei24View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei24View

IMPLEMENT_DYNCREATE(CRei24View, CFormView)

BEGIN_MESSAGE_MAP(CRei24View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei24View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei24View コンストラクション/デストラクション

CRei24View::CRei24View()
	: CFormView(CRei24View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei24View::~CRei24View()
{
}

void CRei24View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei24View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei24View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei24View 診断

#ifdef _DEBUG
void CRei24View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei24View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei24Doc* CRei24View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei24Doc)));
	return (CRei24Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei24View メッセージ ハンドラ
/*
 * -----------------------------------------
 *      文字列の置き換え（リプレイス）     *
 * -----------------------------------------
 */

#include "mfcform.h"
char *search(char *text,char *key) //この関数を先に置く
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
    char *p;
    int i;
    p=search(text,key);
    while (p!=NULL){
        for (i=0;i<(int)strlen(rep);i++)      /* 置き換え */
            p[i]=rep[i];
        p=search(p+strlen(key),key);
    }
}


void CRei24View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    static char text[]="This is a pen. That is a pencil.";
	tinit();cls();
    replace(text,"pen","cap");      /* 同じ長さであること */
    printf("%s\n",text);
	tfin();
}
