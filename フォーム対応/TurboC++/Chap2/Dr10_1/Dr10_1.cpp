//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr10_1.h"
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
 * ---------------------------------------------
 *      テイラー展開（ｅｘｐ（ｘ）改良版）     *
 * ---------------------------------------------
 */

#include "turboform.h"
double myexp(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d,a;
    int k;

    a=fabs(x);
    for (k=1;k<=200;k++){
        d=s;
        e=e*a/k;
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d)){      /* 打ち切り誤差 */
            if (x>0)
                return s;
            else
                return 1.0/s;
        }
    }
    return 0.0;        /* 収束しないとき */
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x;
	tinit();cls();
    printf("    x       myexp(x)        exp(x)\n");
    for (x=-40;x<=40;x=x+10)
        printf("%5.1f%14.6g%14.6g\n",x,myexp(x),exp(x));

}
//---------------------------------------------------------------------------
