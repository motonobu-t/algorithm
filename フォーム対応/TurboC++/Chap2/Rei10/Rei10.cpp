//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei10.h"
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
 * ---------------------------------------
 *      �e�C���[�W�J�i�������i���j�j     *
 * ---------------------------------------
 */

#include "turboform.h"

double myexp(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d;
    int k;

    for (k=1;k<=200;k++) {
        d=s;
        e=e*x/k;
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d))      /* �ł��؂�덷 */
            return s;
    }
    return 0.0;    /* �������Ȃ��Ƃ� */
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x;
	tinit();cls();
    printf("    x      myexp(x)        exp(x)\n");
    for (x=0;x<=40;x=x+10)
        printf("%5.1f%14.6g%14.6g\n",x,myexp(x),exp(x));

}
//---------------------------------------------------------------------------
