//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei29.h"
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
 *      �n�m�C�̓��̍ċA��      *
 * ------------------------------
 */

#include "turboform.h"
void hanoi(int n,char a,char b,char c)  /* �ċA�葱 */
{
    if (n>0) { 
        hanoi(n-1,a,c,b);    
        printf("%d�Ԃ̉~�Ղ� %c ���� %c �Ɉړ�\n",n,a,b);
        hanoi(n-1,c,b,a);
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n;
	n=stoi(Edit1->Text);
	tinit();cls();
    hanoi(n,'a','b','c');

}
//---------------------------------------------------------------------------
