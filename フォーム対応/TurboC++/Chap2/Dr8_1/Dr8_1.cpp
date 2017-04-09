//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr8_1.h"
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
 * ----------------------
 *     一様性の検定　   *
 * ----------------------
 */

#include "turboform.h"

#define N 1000             /* 乱数の発生回数 */
#define M 10               /* 整数乱数の範囲 */
#define F (N/M)            /* 期待値 */
#define SCALE (40.0/F)     /* ヒストグラムの高さ（自動スケール） */

unsigned rndnum=13;        /* 乱数の初期値 */
unsigned irnd(void)        /* 0～32767の整数乱数 */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0～1未満の実数乱数 */
{
    return irnd()/32767.1;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,j,rank,hist[M+1];
    double e=0.0;

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1～Mの乱数を１つ発生 */
        hist[rank]++;
    }

	tinit();cls();
    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* ヒストグラムの表示 */
            printf("*");
        printf("\n");

        e=e+(double)(hist[i]-F)*(hist[i]-F)/F;        /* χ2の計算 */
    }
    printf("χ2=%f\n",e);

}
//---------------------------------------------------------------------------
