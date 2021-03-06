//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr63_4.h"
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
 * -------------------------
 *      ヒルベルト曲線     *
 * -------------------------
 */

#include "turboform.h"
void hilbert(int n,double l,double angle)
{
    if (n==0)
        return;
    turn(angle);hilbert(n-1,l,-angle);move(l);
    turn(-angle);hilbert(n-1,l,angle);move(l);
    hilbert(n-1,l,angle);turn(-angle);move(l);
    hilbert(n-1,l,-angle);turn(angle);
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int n=4;         /* 次数 */

    ginit(); cls();

    setpoint(200,100);
	hilbert(n,10,90);
}
//---------------------------------------------------------------------------
