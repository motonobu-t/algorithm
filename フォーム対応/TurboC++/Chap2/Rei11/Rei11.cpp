//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei11.h"
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
 *      ÇQï™ñ@     *
 * -----------------
 */

#include "turboform.h"

#define f(x) ((x)*(x)*(x)-(x)+1)
#define EPS 1e-8                /* ë≈ÇøêÿÇËåÎç∑ */
#define LIMIT 50                /* ë≈ÇøêÿÇËâÒêî */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double low,high,x;
    int k;
	tinit();cls();
    low=-2.0; high=2.0;
    for (k=1;k<=LIMIT;k++) {
        x=(low+high)/2;
        if (f(x)>0)
            high=x;
        else
            low=x;
        if (f(x)==0 || fabs(high-low)<fabs(low)*EPS){
            printf("x=%f\n",x);
            break;
        }
    }
    if (k>LIMIT)
        printf("é˚ë©ÇµÇ»Ç¢\n");
}
//---------------------------------------------------------------------------
