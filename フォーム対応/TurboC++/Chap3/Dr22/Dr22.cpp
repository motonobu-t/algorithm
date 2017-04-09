//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr22.h"
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

#define M 13
#define N 5
#define MaxEof 9999        /* 番兵 */
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a[]={2,4,5,7,8,10,15,20,30,40,45,50,60,MaxEof},
        b[]={6,11,25,33,35,MaxEof},
        c[M+N];
    int i,j,p;

    i=j=p=0;
    while (a[i]!=MaxEof || b[j]!=MaxEof){
        if (a[i]<=b[j])
            c[p++]=a[i++];
        else
            c[p++]=b[j++];
    }

	tinit();cls();
    for (i=0;i<M+N;i++)
        printf("%d ",c[i]);
    printf("\n");

}
//---------------------------------------------------------------------------
