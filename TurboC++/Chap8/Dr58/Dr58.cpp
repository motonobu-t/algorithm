//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr58.h"
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
 * -------------------
 *      √２分割     *
 * -------------------
 */

#include "turboglib.h"

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int k;
    double leng=400.0,            /* 対角線の初期値 */
           rd=3.14159/180,
           x,y;

    ginit(); cls();
    setpoint(0,380); setangle(-54.7);
    for (k=1;k<=10;k++){
        move(leng);                 /* 対角線を引く */
        x=leng*cos(54.7*rd);        /* ｘ方向の長さ */
        y=leng*sin(54.7*rd);        /* ｙ方向の長さ */
        turn(180-35.3); move(y);    /* 長方形を描く */
        turn(90); move(x);
        turn(90); move(y);
        turn(90); move(x);
        turn(35.3);
        leng=leng/sqrt(2.0);
    }
}
//---------------------------------------------------------------------------
