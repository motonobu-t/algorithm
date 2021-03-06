//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dr57.h"
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
 * ------------------------
 *     �Q������]�ϊ�     *
 * ------------------------
 */

#include "turboform.h"

void multi(double factx,double facty,double *x,double *y)
{
    *x=factx*(*x);
    *y=facty*(*y);
}
void rotate(double deg,double *x,double *y)	/* ��]�ϊ� */
{
    double dx,dy,rd=3.14159/180;
    dx=(*x)*cos(deg*rd)-(*y)*sin(deg*rd);
    dy=(*x)*sin(deg*rd)+(*y)*cos(deg*rd);
    *x=dx; *y=dy;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x[]={0,100,100,  0,0},
           y[]={0,  0,200,200,0};
    int j,k,n=5;

    ginit(); cls(); window(-320,-200,320,200);

    for (j=0;j<12;j++){
        for (k=0;k<n;k++){
            multi(.8,.8,&x[k],&y[k]);
            rotate(30,&x[k],&y[k]);
            if (k==0)
                setpoint(x[k],y[k]);
            else
                moveto(x[k],y[k]);
        }
	}
}
//---------------------------------------------------------------------------
