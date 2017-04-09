//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei12.h"
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
 * ---------------------------
 *      ƒ‰ƒOƒ‰ƒ“ƒWƒ…•âŠÔ     *
 * ---------------------------
 */

#include "turboform.h"

double lagrange(double x[],double y[],int n,double t)
{
    int i,j;
    double s,p;

    s=0.0;
    for (i=0;i<n;i++){
        p=y[i];
        for (j=0;j<n;j++){
            if (i!=j)
                p=p*(t-x[j])/(x[i]-x[j]);
        }
        s=s+p;
    }
    return s;
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x[]={0.0,1.0,3.0,6.0,7.0},
           y[]={0.8,3.1,4.5,3.9,2.8};

    double t;
	tinit();cls();
    printf("      x      y\n");
    for (t=0.0;t<=7.0;t=t+.5)
        printf("%7.2f%7.2f\n",t,lagrange(x,y,5,t));

}
//---------------------------------------------------------------------------
