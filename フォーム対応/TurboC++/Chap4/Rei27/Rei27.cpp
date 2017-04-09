//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei27.h"
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
 * ---------------------------
 *     ŠKæŒvŽZ‚Ì”ñÄ‹A‰ð    *
 * ---------------------------
 */

#include "turboform.h"
long kaijo(int n)   /* ŠKæ */
{
    int k;
    long p=1L;

    for (k=n;k>=1;k--)
        p=p*k;
    return p;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n;
	tinit();cls();
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));

}
//---------------------------------------------------------------------------
