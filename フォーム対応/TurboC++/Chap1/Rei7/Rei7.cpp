//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei7.h"
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
 * -----------------------
 *       �f���̔���      *
 * -----------------------
 */

#include "turboform.h"
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,n,Limit;

	n=stoi(Edit1->Text);

	tinit();cls();
    if (n>=2){
        Limit=(int)sqrt((double)n);
        for (i=Limit;i>1;i--){
            if (n%i == 0)
                break;
        }
        if (i==1)
            printf("�f��\n");
        else
            printf("�f���łȂ�\n");
	}
}
//---------------------------------------------------------------------------
