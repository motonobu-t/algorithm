/*
 * --------------------
 *      ���̃��f��    *
 * --------------------
 */

#include "glib.h"

void rotate(double,double,double,double,double,double,double *,double *);

void main(void)
{
    int k,n;
    double ax,ay,az,rd=3.14159/180;
    double x[]={ 0,20,  0, 60,100,60, 0,-999},   /* �����W */
           z[]={40,60,100,120, 60,20,40,-999},   /* �����W */
           h=100.0,                              /* ���� */
           btx[30],bty[30],                      /* ��� */
           tpx[30],tpy[30];                      /* ��� */
    ax=35*rd;                       /* �������̉�]�p */
    ay=-60*rd;                      /* �������̉�]�p */
    az=0;

    ginit(); cls();
    window(-320,-200,320,200);

    for (k=0;(int)x[k]!=-999;k++){      /* ��� */
        rotate(ax,ay,az,x[k],0.0,z[k],&btx[k],&bty[k]);
        if (k==0)
            setpoint(btx[k],bty[k]);
        else
            moveto(btx[k],bty[k]);
    }
    n=k;
    for (k=0;k<n;k++){                  /* ��� */
        rotate(ax,ay,az,x[k],h,z[k],&tpx[k],&tpy[k]);
        if (k==0)
            setpoint(tpx[k],tpy[k]);
        else
            moveto(tpx[k],tpy[k]);
    }
    for (k=0;k<n;k++)       /* ��ʂƏ�ʂ̊e�_������ */
        line(tpx[k],tpy[k],btx[k],bty[k]);
}
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
