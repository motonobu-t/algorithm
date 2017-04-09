//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
 * ---------------------------------------------
 *      ハノイの塔（シミュレ－ション付き）     *
 * ---------------------------------------------
 */

#include "turboform.h"
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
	MessageBox(NULL,"次の移動","",MB_OK); // 次の表示まで待つ
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int i;
	N=stoi(Edit1->Text);

    for (i=0;i<N;i++)               /* 棒ａに円盤を積む */
        pie[i][0]=N-i;
    sp[0]=N; sp[1]=0; sp[2]=0;      /* スタック・ポインタの初期設定 */
	tinit();cls();
	hanoi(N,0,1,2);
}
//---------------------------------------------------------------------------
