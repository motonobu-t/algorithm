//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr12.h"
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
 * -------------------------
 *      ニュートン補間     *
 * -------------------------
 */

#include "turboform.h"
double newton(double x[],double y[],int n,double t)
{
    static int flag=1;
    static double a[100];      /* 係数配列 */
    double        w[100],      /* 作業用   */
           s;
    int i,j;

    if (flag==1){    /* １度目に呼ばれた時だけ a[] に係数を求める */
        for (i=0;i<n;i++){
            w[i]=y[i];
            for (j=i-1;j>=0;j--)
                w[j]=(w[j+1]-w[j])/(x[i]-x[j]);
            a[i]=w[0];
        }
        flag=-1;
    }

    s=a[n-1];               /* x=t における補間 */
    for (i=n-2;i>=0;i--)
        s=s*(t-x[i])+a[i];
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
        printf("%7.2f%7.2f\n",t,newton(x,y,5,t));
}
//---------------------------------------------------------------------------
