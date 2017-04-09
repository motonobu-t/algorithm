//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr56.h"
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
 * ----------------------
 *      �Q�����͗l      *
 * ----------------------
 */

#include "turboglib.h"

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    double leng=200.0,    /* �ӂ̏����l */
           angle=89.0,    /* ��]�p */
           step=1.0;      /* �ӂ̌����l */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}
//---------------------------------------------------------------------------
