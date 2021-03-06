//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei22.h"
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
 * --------------------------
 *      マージ （併合）     *
 * --------------------------
 */

#include "turboform.h"

#define M 10
#define N 5
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={2,4,5,7,8,10,15,20,30,40},
        b[]={6,11,25,33,35},
        c[M+N];
    int i,j,p;

    i=j=p=0;
    while (i<M && j<N){        /* a[],b[]とも終わりでない間 */
        if (a[i]<=b[j])
            c[p++]=a[i++];
        else
            c[p++]=b[j++];
    }
    while (i<M)                /* a[]が終わりになるまで */
        c[p++]=a[i++];
    while (j<N)                /* b[]が終わりになるまで */
        c[p++]=b[j++];

	tinit();cls();
    for (i=0;i<M+N;i++)
        printf("%d ",c[i]);
	printf("\n");
}
//---------------------------------------------------------------------------
