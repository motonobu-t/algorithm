//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei28.h"
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
 * -------------------------------------
 *      順列生成（辞書式順でない）     *
 * -------------------------------------
 */

#include "turboform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[i]; p[i]=p[j]; p[j]=t;    /* p[i]とp[j]の交換 */
            perm(i+1);                    /* 再帰呼び出し */
            t=p[i]; p[i]=p[j]; p[j]=t;    /* 元に戻す */
        }
    }
    else {
        for (j=1;j<=N;j++)                /* 順列の表示 */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i;

    for (i=1;i<=N;i++)        /* 初期設定 */
        p[i]=i;
	tinit();cls();  // 再帰呼び出しの前後でtinit()とtfin()を入れる
    perm(1);

}
//---------------------------------------------------------------------------
