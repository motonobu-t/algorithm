//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr64.h"
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
 *      ÇSÇmñÇï˚êw     *
 * ---------------------
 */

#include "turboform.h"

#define N 8     /* ÇSÇmï˚êw(n=4,8,12,16,•••) */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int hojin[N+1][N+1],i,j;
	tinit();cls();
    for (j=1;j<=N;j++){
        for (i=1;i<=N;i++){
            if (j%4==i%4 || (j%4+i%4)%4==1)
                hojin[i][j]=(N+1-i)*N-j+1;
            else
                hojin[i][j]=(i-1)*N+j;
        }
    }

    printf("        ÇSÇmñÇï˚êw (N=%d)\n",N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++)
            printf("%4d",hojin[i][j]);
        printf("\n");
    }
}
//---------------------------------------------------------------------------
