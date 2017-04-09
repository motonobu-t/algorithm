//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei4.h"
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
 * ---------------------------------------
 *    ランダムな順列（効率の悪い方法）   *
 * ---------------------------------------
 */

#include "turboform.h"

#define N 20

int irnd(int n)        /* １～ｎの乱数 */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,j,flag,a[N+1];

    a[1]=irnd(N);
    for (i=2;i<=N;i++){
        do {
            a[i]=irnd(N);flag=0;
            for (j=1;j<i;j++)
                if (a[i]==a[j]){
                    flag=1;break;
                }
        } while (flag==1);
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
}
//---------------------------------------------------------------------------
