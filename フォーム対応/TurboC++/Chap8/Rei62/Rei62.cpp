//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei62.h"
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
 *       コッホ曲線      *
 * -----------------------
 */

#include "turboform.h"
void koch(int n,double leng)        /* コッホ曲線の再帰手続き */
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int    n=4;         /* コッホ次数 */
    double leng=4.0;    /* ０次の長さ */

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

	koch(n,leng);
}
//---------------------------------------------------------------------------
