// Dr65View.cpp : CDr65View クラスの実装
//

#include "stdafx.h"
#include "Dr65.h"

#include "Dr65Doc.h"
#include "Dr65View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr65View

IMPLEMENT_DYNCREATE(CDr65View, CFormView)

BEGIN_MESSAGE_MAP(CDr65View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr65View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr65View コンストラクション/デストラクション

CDr65View::CDr65View()
	: CFormView(CDr65View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr65View::~CDr65View()
{
}

void CDr65View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr65View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr65View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr65View 診断

#ifdef _DEBUG
void CDr65View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr65View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr65Doc* CDr65View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr65Doc)));
	return (CDr65Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr65View メッセージ ハンドラ
/*
 * -------------------------------
 *      戦略を持つじゃんけん     *
 * -------------------------------
 */

#include "mfcform.h"

int man,computer,C=0,M=0,judge;
int table[3][3][3]={{{0,0,0},{0,0,0},{0,0,0}},    /* 戦略テーブル */
                    {{0,0,0},{0,0,0},{0,0,0}},
                    {{0,0,0},{0,0,0},{0,0,0}}},
    hist[3]={0,0,0};                       /* 勝敗の度数 */
char *hand[3]={"グー","チョキ","パー"};

void CDr65View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	if (table[C][M][0]>table[C][M][1] && table[C][M][0]>table[C][M][2])
        computer=0;
    else if (table[C][M][1]>table[C][M][2])
        computer=1;
    else
        computer=2;
	CString buf;
	text1.GetWindowText(buf);
	man=stoi(buf);

    printf("コンピュータの手 %s\n",hand[computer]);
    judge=(computer-man+3)%3;         /* 判定 */
    switch (judge){
        case 0: printf("ひきわけ\n");
                table[C][M][(computer+2)%3]++;break;
        case 1: printf("あなたの勝ち\n");
                table[C][M][computer]--;break;
        case 2: printf("コンピュータの勝ち\n");
                table[C][M][computer]++;break;
    }
    M=man;               /* １つ前の状態を保存 */
    C=computer;

    hist[judge]++;
    printf("--- %d勝%d敗%d分 ---\n\n",hist[1],hist[2],hist[0]);
	tfin();
}
