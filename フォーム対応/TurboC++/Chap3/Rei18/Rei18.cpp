//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei18.h"
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
 * ---------------------------------
 *      直接選択法によるソート     *
 * ---------------------------------
 */

#include "turboform.h"

#define N 6

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={80,41,35,90,40,20};
    int min,s,t,i,j;

    for (i=0;i<N-1;i++){
        min=a[i];
        s=i;
        for (j=i+1;j<N;j++){
            if (a[j]<min){
                min=a[j];
                s=j;
            }
        }
        t=a[i]; a[i]=a[s]; a[s]=t;
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");

}
//---------------------------------------------------------------------------
