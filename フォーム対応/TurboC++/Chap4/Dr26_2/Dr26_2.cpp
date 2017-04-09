//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr26_2.h"
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
 * ------------------------------
 *      nÇbrÇÃåvéZÅiçƒãAî≈Åj    *
 * ------------------------------
 */

#include "turboform.h"
long combi(int n,int r)
{
    if (r==0 || r==n)
        return 1L;
    else
        return combi(n-1,r)+combi(n-1,r-1);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n,r;
	tinit();cls();
    for (n=0;n<=5;n++) {
        for (r=0;r<=n;r++)
            printf("%dÇb%d=%ld  ",n,r,combi(n,r));
        printf("\n");
	}
}
//---------------------------------------------------------------------------
