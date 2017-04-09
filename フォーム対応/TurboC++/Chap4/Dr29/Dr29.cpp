//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr29.h"
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
 * ------------------------------------------
 *      ƒnƒmƒC‚Ì“ƒiˆø”‚ð‚P‚ÂŒ¸‚ç‚·j      *
 * ------------------------------------------
 */

#include "turboform.h"

#define Total 'a'+'b'+'c'
void hanoi(int n,char a,char b)  /* Ä‹AŽè‘± */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d”Ô‚Ì‰~”Õ‚ð %c ‚©‚ç %c ‚ÉˆÚ“®\n",n,a,b);
        hanoi(n-1,Total-(a+b),b);
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n;
	n=stoi(Edit1->Text);
	tinit();cls();
    hanoi(n,'a','b');

}
//---------------------------------------------------------------------------
