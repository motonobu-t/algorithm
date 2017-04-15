//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr62_2.h"
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
 *       �N���X�E�X�e�b�`       *
 * ------------------------------
 */

#include "turboglib.h"

void stech(int n,double leng)       /* �X�e�b�`�̍ċA�葱�� */
{
    if (n==0)
        move(leng);
    else {
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng);
    }
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int    k,
           n=4;         /* �X�e�b�`�̎��� */
    double leng=2.0;    /* �O���̒��� */

    ginit(); cls();
    setpoint(200,150); setangle(0);
    for (k=1;k<=4;k++){
        stech(n,leng);
        turn(90);
    }
}
//---------------------------------------------------------------------------