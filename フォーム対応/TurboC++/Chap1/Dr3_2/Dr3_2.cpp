//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr3_2.h"
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
 * -----------------------------------
 *       順位付け（負のデータ版）    *
 * -----------------------------------
 */

#include "turboform.h"

#define Num 10
#define Max 36
#define Min -20
#define Bias 1-(Min)    /* 最小値を配列要素の１に対応させる */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={-3,2,3,-1,-2,-6,2,-1,1,5};
    int i,juni[Max+Bias+1];

	for (i=Min+Bias;i<=Max+Bias;i++)
        juni[i]=0;

    for (i=0;i<Num;i++)
        juni[a[i]+Bias]++;

    juni[0]=1;
    for (i=Min+Bias;i<=Max+Bias;i++)
        juni[i]=juni[i]+juni[i-1];

	tinit();cls();
    printf("　得点　順位\n");
    for (i=0;i<Num;i++){
        printf("%6d%6d\n",a[i],juni[a[i]+Bias-1]);
    }
}
//---------------------------------------------------------------------------
