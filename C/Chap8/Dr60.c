/*
 * --------------------
 *      ’Œ‘Ìƒ‚ƒfƒ‹    *
 * --------------------
 */

#include "glib.h"

void rotate(double,double,double,double,double,double,double *,double *);

void main(void)
{
    int k,n;
    double ax,ay,az,rd=3.14159/180;
    double x[]={ 0,20,  0, 60,100,60, 0,-999},   /* ‚˜À•W */
           z[]={40,60,100,120, 60,20,40,-999},   /* ‚šÀ•W */
           h=100.0,                              /* ‚‚³ */
           btx[30],bty[30],                      /* ’ê–Ê */
           tpx[30],tpy[30];                      /* ã–Ê */
    ax=35*rd;                       /* ‚˜²‰ñ‚è‚Ì‰ñ“]Šp */
    ay=-60*rd;                      /* ‚™²‰ñ‚è‚Ì‰ñ“]Šp */
    az=0;

    ginit(); cls();
    window(-320,-200,320,200);

    for (k=0;(int)x[k]!=-999;k++){      /* ’ê–Ê */
        rotate(ax,ay,az,x[k],0.0,z[k],&btx[k],&bty[k]);
        if (k==0)
            setpoint(btx[k],bty[k]);
        else
            moveto(btx[k],bty[k]);
    }
    n=k;
    for (k=0;k<n;k++){                  /* ã–Ê */
        rotate(ax,ay,az,x[k],h,z[k],&tpx[k],&tpy[k]);
        if (k==0)
            setpoint(tpx[k],tpy[k]);
        else
            moveto(tpx[k],tpy[k]);
    }
    for (k=0;k<n;k++)       /* ’ê–Ê‚Æã–Ê‚ÌŠe“_‚ğŒ‹‚Ô */
        line(tpx[k],tpy[k],btx[k],bty[k]);
}
void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   /* ‚RŸŒ³‰ñ“]•ÏŠ· */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          /* ‚™²‰ñ‚è */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           /* ‚˜²‰ñ‚è */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       /* ‚š²‰ñ‚è */
    *py=x2*sin(az)+y2*cos(az);
}
