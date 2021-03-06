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
 *      ハノイの塔（引数を１つ減らす）      *
 * ------------------------------------------
 */

#include "turboform.h"

#define Total 'a'+'b'+'c'
void hanoi(int n,char a,char b)  /* 再帰手続 */
{
    if (n>0) {
        hanoi(n-1,a,Total-(a+b));
        printf("%d番の円盤を %c から %c に移動\n",n,a,b);
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
