//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr7_3.h"
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
 * --------------------
 *     ‘fˆö”•ª‰ð     *
 * --------------------
 */

#include "turboform.h"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int a,n;

	n=stoi(Edit1->Text);
    a=2;

	tinit();cls();
    while (n>=a*a){
        if (n % a ==0){
            printf("%d*",a);n=n/a;
        }
        else
            a++;
    }
	printf("%d\n",n);
}
//---------------------------------------------------------------------------
