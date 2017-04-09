//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr62_1.h"
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
 * ---------------------
 *       �R�b�z��      *
 * ---------------------
 */

#include "turboglib.h"

void koch(int n,double leng)        /* �R�b�z�Ȑ��̍ċA�葱�� */
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

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int    i,
           n=4;         /* �R�b�z���� */
    double leng=4.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(150,300);
    setangle(0);
    for (i=0;i<3;i++){
          koch(n,leng);
        turn(-120);
    }
}
//---------------------------------------------------------------------------
