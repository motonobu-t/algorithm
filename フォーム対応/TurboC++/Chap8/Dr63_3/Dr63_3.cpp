//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr63_3.h"
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
 *      ドラゴン・カーブ     *
 * ---------------------------
 */

#include "turboform.h"
void dragon(int n,double a)
{
    if (n==0){
        move(5);
    }
    else {
        dragon(n-1,90);
        turn(a);
        dragon(n-1,-90);
    }
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n=10;       /* 次数 */

    ginit(); cls();

    setpoint(200,100);
	dragon(n,90);
}
//---------------------------------------------------------------------------
