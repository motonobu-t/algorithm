//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr26_1.h"
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
 * ------------------------------------
 *      フィボナッチ数（再帰版）      *
 * ------------------------------------
 */

#include "turboform.h"
long fib(long n)
{
    if (n==1 || n==2)
        return 1L;
    else
        return fib(n-1)+fib(n-2);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    long n;
	tinit();cls();
    for (n=1;n<=20;n++)
        printf("%3ld: %ld\n",n,fib(n));

}
//---------------------------------------------------------------------------
