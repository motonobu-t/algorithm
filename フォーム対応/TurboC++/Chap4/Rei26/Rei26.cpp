//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei26.h"
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
 * -------------------------
 *     �K��v�Z�̍ċA��    *
 * -------------------------
 */

#include "turboform.h"
long kaijo(int n)   /* �ċA�葱 */
{
    if (n==0)
        return 1L;
    else
        return n*kaijo(n-1);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n;
	tinit();cls();
    for (n=0;n<13;n++)
        printf("%2d!= %10ld\n",n,kaijo(n));

}
//---------------------------------------------------------------------------
