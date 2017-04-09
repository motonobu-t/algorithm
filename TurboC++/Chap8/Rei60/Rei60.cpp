//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Rei60.h"
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
 * -------------------------------------
 *      ��]�̃��f���i���C���O���X�j   *
 * -------------------------------------
 */

#include "turboglib.h"

void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   /* �R������]�ϊ� */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          /* ������� */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           /* ������� */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       /* ������� */
    *py=x2*sin(az)+y2*cos(az);
}

void __fastcall TForm1::FormPaint(TObject *Sender)
{
    int n,k;
    double x,z,px,py,ax,ay,az,rd=3.14159/180;
	double y[]={180,140,100,60,20,10,4,0,-999},   /* ���� */
           r[]={100,55,10,10,10,50,80,80,-999};   /* ���a */
    ax=35*rd;   /* �������̉�]�p */
    ay=0;       /* �������̉�]�p */
    az=20*rd;   /* �������̉�]�p */

    ginit(); cls();
    window(-320,-100,320,300);

    for (k=0;(int)y[k]!=-999;k++){    /* �������̉�]�O�� */
        for (n=0;n<=360;n=n+10){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (n==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
    for (n=0;n<=360;n=n+60){        /* �Ő� */
        for (k=0;(int)y[k]!=-999;k++){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (k==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
	}
}
//---------------------------------------------------------------------------
