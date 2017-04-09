//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei64.h"
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
 * ---------------------
 *      Šï”–‚•ûw     *
 * ---------------------
 */
#include "turboform.h"

#define N 7     /* ‚•ûw(n=3,5,7,9,¥¥¥) */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int hojin[N+1][N+1],i,j,k;
	tinit();cls();
    j=(N+1)/2; i=0;
    for (k=1;k<=N*N;k++){
        if ((k%N)==1)
            i++;
        else {
            i--; j++;
        }
        if (i==0)
            i=N;
        if (j>N)
            j=1;
        hojin[i][j]=k;
    }

    printf("        Šï”–‚•ûw (N=%d)\n",N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++)
            printf("%4d",hojin[i][j]);
        printf("\n");
    }

}
//---------------------------------------------------------------------------
