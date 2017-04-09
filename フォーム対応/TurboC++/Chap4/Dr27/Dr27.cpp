//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr27.h"
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
 * --------------------------------------
 *      フィボナッチ数（非再帰版）      *
 * --------------------------------------
 */

#include "turboform.h"
long fib(long n)
{
    long a,b,dummy,k;
    a=1L; b=1L;
    for (k=3;k<=n;k++){
        dummy=b;
        b=a+b;
        a=dummy;
    }
    return b;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    long n;
	tinit();cls();
    for (n=1;n<=20;n++)
		printf("%3ld: %ld\n",n,fib(n));
}
//---------------------------------------------------------------------------
