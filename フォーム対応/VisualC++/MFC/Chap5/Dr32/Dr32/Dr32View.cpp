// Dr32View.cpp : CDr32View クラスの実装
//

#include "stdafx.h"
#include "Dr32.h"

#include "Dr32Doc.h"
#include "Dr32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr32View

IMPLEMENT_DYNCREATE(CDr32View, CFormView)

BEGIN_MESSAGE_MAP(CDr32View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr32View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr32View コンストラクション/デストラクション

CDr32View::CDr32View()
	: CFormView(CDr32View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr32View::~CDr32View()
{
}

void CDr32View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr32View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr32View 診断

#ifdef _DEBUG
void CDr32View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr32View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr32Doc* CDr32View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr32Doc)));
	return (CDr32Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr32View メッセージ ハンドラ
/*
 * ---------------------------------------------
 *      ハノイの塔（シミュレ－ション付き）     *
 * ---------------------------------------------
 */

#include "mfcform.h"

int pie[20][3];        /* 20:円盤の最大枚数, 3:棒の数 */
int sp[3],N;           /* スタック・ポインタ */

void move(int n,int s,int d)        /* 円盤の移動シミュレーション */
{
    int i,j;

    pie[sp[d]][d]=pie[sp[s]-1][s];  /* ｓ－＞ｄへ円盤の移動 */
    sp[d]++;                        /* スタック・ポインタの更新 */
    sp[s]--;

	printf("\n"); 
	printf("%d 番の円盤を %c-->%c に移す\n",n,'a'+s,'a'+d);
	printf("\n");   
	for (i=N-1;i>=0;i--){
        for (j=0;j<3;j++){
            if (i<sp[j])
                printf("%8d",pie[i][j]);
            else
                printf("        ");
        }
        printf("\n");
    }
	printf("\n");
    printf("       a       b       c\n");
	AfxMessageBox(CString("次の移動"),MB_OK); // 次の表示まで待つ
	cls();

}
void hanoi(int n,int a,int b,int c)  /* 再帰手続 */
{
    if (n>0) {
        hanoi(n-1,a,c,b);
        move(n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void CDr32View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
	CString buf;
	text1.GetWindowText(buf);
	N=stoi(buf);

    for (i=0;i<N;i++)               /* 棒ａに円盤を積む */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* スタック・ポインタの初期設定 */
	tinit();cls();
    hanoi(N,0,1,2);
	tfin();
}
