//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr6.h"
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
 * ---------------------------------
 *      ユークリッドの互除法       *
 * ---------------------------------
 */

#include "turboform.h"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a,b,m,n,k;

	a=stoi(Edit1->Text);
	b=stoi(Edit2->Text);
    m=a; n=b;
    do{
        k=m % n;
        m=n; n=k;
    } while(k!=0);

	tinit();cls();
	printf("最大公約数=%d\n",m);
}
//---------------------------------------------------------------------------
