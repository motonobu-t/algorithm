//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei19.h"
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
 *      基本挿入法     *
 * ---------------------
 */

#include "turboform.h"

#define N 100     /* データ数 */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[N],i,j,t;

    for(i=0;i<N;i++)       /* Ｎ個の乱数 */
        a[i]=rand();

    for (i=1;i<N;i++){
        for (j=i-1;j>=0;j--){
            if (a[j]>a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
            else
                break;
        }
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");

}
//---------------------------------------------------------------------------
