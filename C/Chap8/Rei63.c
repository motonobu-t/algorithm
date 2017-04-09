/*
 * -------------------------
 *      ���؋Ȑ����̂P     *
 * -------------------------
 */

#include "glib.h"

void tree(int,double,double,double,double);

double scale,branch;

void main(void)
{
    int n;
    double x0,y0,leng,angle;

    n=8;                /* �}�̎��� */
    x0=300.0;y0=50.0;   /* ���̈ʒu */
    leng=100.0;         /* �}�̒��� */
    angle=90.0;         /* �}�̌��� */
    scale=1.4;          /* �}�̐L�ї� */
    branch=20.0;        /* �}�̕���p */

    ginit(); cls();
    tree(n,x0,y0,leng,angle);
}
void tree(int n,double x0,double y0,double leng,double angle)
                                        /* ���؋Ȑ��̍ċA�葱�� */
{
    if (n==0)
        return;

    setpoint(x0,y0); setangle(angle);
    move(leng);

    x0=LPX; y0=LPY;
    tree(n-1,x0,y0,leng/scale,angle-branch);
    tree(n-1,x0,y0,leng/scale,angle+branch);
}
