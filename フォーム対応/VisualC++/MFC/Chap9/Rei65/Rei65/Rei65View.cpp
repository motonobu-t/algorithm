// Rei65View.cpp : CRei65View クラスの実装
//

#include "stdafx.h"
#include "Rei65.h"

#include "Rei65Doc.h"
#include "Rei65View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei65View

IMPLEMENT_DYNCREATE(CRei65View, CFormView)

BEGIN_MESSAGE_MAP(CRei65View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei65View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei65View コンストラクション/デストラクション

CRei65View::CRei65View()
	: CFormView(CRei65View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei65View::~CRei65View()
{
}

void CRei65View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei65View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei65View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei65View 診断

#ifdef _DEBUG
void CRei65View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei65View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei65Doc* CRei65View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei65Doc)));
	return (CRei65Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei65View メッセージ ハンドラ
/*
 * -------------------------------
 *      戦略を持つじゃんけん     *
 * -------------------------------
 */

#include "mfcform.h"

int man,computer,M=0,judge;
int table[3][3]={{0,0,0},    /* 戦略テーブル */
                 {0,0,0},
                 {0,0,0}},
    hist[3]={0,0,0};    /* 勝敗の度数 */
char *hand[3]={"グー","チョキ","パー"};

void CRei65View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	if (table[M][0]>table[M][1] && table[M][0]>table[M][2])
        computer=2;
    else if (table[M][1]>table[M][2])
        computer=0;
    else
        computer=1;

	CString buf;
	text1.GetWindowText(buf);
	man=stoi(buf);
    printf("コンピュータの手 %s\n",hand[computer]);

    judge=(computer-man+3)%3;
    switch (judge){
        case 0: printf("ひきわけ\n");break;
        case 1: printf("あなたの勝ち\n");break;
        case 2: printf("コンピュータの勝ち\n");break;
    }
    hist[judge]++;
    table[M][man]++;        /* 学習 */
    M=man;
    printf("--- %d勝%d敗%d分 ---\n\n",hist[1],hist[2],hist[0]);
	tfin();
}
