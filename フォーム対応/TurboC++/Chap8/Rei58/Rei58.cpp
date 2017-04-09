//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei58.h"
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
 * --------------------
 *       対称模様     *
 * --------------------
 */

#include "turboform.h"

#define N 9     /* データ数 */

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    double x[]={ 35, 19,10, 3,0,-3,-10,-19,-35},
           y[]={-20,-20,-5,-5,0,-5, -5,-20,-20};
    int a,b,j,k;
    double rd=3.14159/180,
           m,h,vy,vx,px,py;

    ginit(); cls();
    m=70.0; h=m*sqrt(3.0)/2;      /* 正３角形の辺の長さ、高さ */
    window(-m/2,-h/3,m/2,h*2/3);
    b=1;
    for (vy=0.0;vy<=310.0;vy=vy+h){
        a=1;
        for (vx=50.0;vx<=500.0;vx=vx+m/2){
            view(vx,vy,vx+m,vy+h);        /* ビューポートの設定 */
            for (j=0;j<3;j++){
                for (k=0;k<N;k++){
                    px=x[k]*cos(120*j*rd)-y[k]*sin(120*j*rd);
                    py=x[k]*sin(120*j*rd)+y[k]*cos(120*j*rd);
                    if (a*b==-1)
                        py=-py+h/3;        /* 逆像補正 */
                    if (k==0)
                        setpoint(px,py);
                    else
                        moveto(px,py);
                }
            }
            a=-a;
        }
        b=-b;
	}
}
//---------------------------------------------------------------------------
