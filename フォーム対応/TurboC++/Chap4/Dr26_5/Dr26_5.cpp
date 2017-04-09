//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr26_5.h"
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
 *      ユークリッドの互除法（再帰版）      *
 * ------------------------------------------
 */

#include "turboform.h"

int gcd(int m,int n)
{
    if (n==0)
        return m;
    else
        return gcd(n,m % n);
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int a,b;

	a=stoi(Edit1->Text);
	b=stoi(Edit2->Text);

	tinit();cls();
	printf("最大公約数=%d\n",gcd(a,b));

}
//---------------------------------------------------------------------------
