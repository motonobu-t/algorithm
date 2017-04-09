//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr26_3.h"
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
 *      Ｈｏｒｎｅｒの方法（再帰版）     *
 * ---------------------------------------
 */

#include "turboform.h"

#define N 4        /* 次数 */
double fn(double x,double a[],int i)
{
    if (i==0)
        return a[N];
    else
        return fn(x,a,i-1)*x+a[N-i];
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double a[]={1,2,3,4,5};
	tinit();cls();
    printf("%f\n",fn(2,a,N));

}
//---------------------------------------------------------------------------
