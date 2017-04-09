//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr1_1.h"
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
 * --------------------------
 *     ÇgÇèÇíÇéÇÖÇíÇÃï˚ñ@   *
 * --------------------------
 */

#include "turboform.h"

double fn(double x,double a[],int n)
{
	double p;
	int i;

    p=a[n];
    for (i=n-1;i>=0;i--)
        p=p*x+a[i];
    return p;
}


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	double a[]={1,2,3,4,5};    /* åWêî */
	double x;
	tinit();
	for (x=1;x<=5;x++)
		printf("fn(%f)=%f\n",x,fn(x,a,4));
}
//---------------------------------------------------------------------------

