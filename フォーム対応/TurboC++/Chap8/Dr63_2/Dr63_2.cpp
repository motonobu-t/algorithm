//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr63_2.h"
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
 * -----------------
 *      Çbã»ê¸     *
 * -----------------
 */

#include "turboform.h"
void ccurve(int n)
{
    if (n==0){
        move(5);
    }
    else {
        ccurve(n-1);
        turn(90);
        ccurve(n-1);
        turn(-90);
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n=10;       /* éüêî */

    ginit(); cls();

    setpoint(200,100);
	ccurve(n);
}
//---------------------------------------------------------------------------
